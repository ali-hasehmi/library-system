#include "ioworker.h"

#include <conio.h>

IOworker::IOworker()
    : mp_worker_thread(nullptr),
      m_last_key(0),
      m_is_worker_on(false)
{
}

IOworker::~IOworker()
{
    // If Worker was already stopped
    if(!this->m_is_worker_on)
    {
        return;
    }

    // Otherwise...
    // Set worker off
    this->m_is_worker_on = false;

    // Wait for thread to stop executing
    this->mp_worker_thread->join();

    // Finally Delete the Space Allocated for Thread
    delete this->mp_worker_thread;

}

int IOworker::stop()
{
    // if the worker was already stopped then it will return -1
    if (!this->m_is_worker_on)
    {
        return -1;
    }

    // otherwise it will set the worker to off
    this->m_is_worker_on = false;

    // And Wait for worker to finish its work
    this->mp_worker_thread->join();

    // Delete the Thread Worker
    delete this->mp_worker_thread;

    // Set the worker Pointer to nullptr, indicating there is no worker
    this->mp_worker_thread = nullptr;

    // Finally returning 0, indicating Success
    return 0;
}

int IOworker::start()
{
    // If worker was already started, return -1
    if (this->m_is_worker_on)
    {
        return -1;
    }

    // Otherwise set worker to on
    this->m_is_worker_on = true;

    // Create the thread Worker and passing captureKeyWorker as an argument to constructor
    this->mp_worker_thread = new std::thread(&IOworker::captureKeyWorker, this);

    return 0;
}

uint32_t IOworker::key()
{
    // first lock the last key variable from modification
    m_mutex.lock();

    // store the current value in a temporary variable
    uint32_t temp = this->m_last_key;

    // set the value of last key to KEY_NULL
    this->m_last_key = KEY_NULL;

    // finally unlock the data
    m_mutex.unlock();

    // returning the value
    return temp;
}



uint32_t IOworker::parseArrowKey()
{
    switch (getch())
    { // the real value
    case 72:
        // code for arrow up
        return KEY_UP;
        break;
    case 80:
        // code for arrow down
        return KEY_DOWN;
        break;
    case 77:
        // code for arrow right
        return KEY_RIGHT;
        break;
    case 75:
        // code for arrow left
        return KEY_LEFT;
        break;
    default:

        return KEY_NULL;
        break;
    }
}

void IOworker::captureKeyWorker()
{
    uint32_t value = 0;
    while (this->m_is_worker_on)
    {
        if (kbhit())
        {
            value = getch();
            if (value == 224)
            { // if the first value is esc
                value = parseArrowKey();
            }
            m_mutex.lock();
            this->m_last_key = value;
            m_mutex.unlock();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
