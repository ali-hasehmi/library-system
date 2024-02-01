/*
IOWorker Object is a asynchronous Object
Which Gets input from the stdin
*/

/*
For Now It only works in windows because it utilizes the conio.h library.
*/
#ifndef IOWORKER_H
#define IOWORKER_H

#include <thread>
#include <mutex>

#define KEY_UP 1003    // Up arrow key
#define KEY_DOWN 1001  // Down arrow key
#define KEY_LEFT 1000  // Left arrow key
#define KEY_RIGHT 1002 // Right arrow key
#define KEY_ENTER 13   // Enter key *** ONLY FOR WINDOWS ***
#define KEY_NULL 0     // Means there is no valid key
#define KEY_EXIT 27    // Exit Key

class IOworker
{

public:

    IOworker();
    ~IOworker();

    int start();
    int stop();
    uint32_t key();
    
private:
    uint32_t parseArrowKey();
    void captureKeyWorker();
    std::thread *mp_worker_thread;
    std::mutex m_mutex;
    uint32_t m_last_key;
    bool m_is_worker_on;
};

#endif // IOWORKER_H