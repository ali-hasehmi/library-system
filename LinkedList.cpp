#include "LinkedList.h"

template <typename U>
Node<U>::Node()
    : mp_next(nullptr),
      mp_previous(nullptr)
{
}

template <typename U>
Node<U>::Node(const U &_value)
    : m_data(_value),
      mp_next(nullptr),
      mp_previous(nullptr)
{
}

template <typename U>
Node<U>::Node(const U &_value, U *_next, U *_previous)
    : m_data(_value),
      mp_next(_next),
      mp_previous(_previous)
{
}

template <typename U>
Node<U>::~Node()
{
}

template <typename T>
inline LinkedList<T>::LinkedList()
    : m_size(0),
      mp_head(nullptr),
      mp_tail(nullptr)
{
}

template <typename T>
LinkedList<T>::~LinkedList()
{
}

template <typename T>
bool LinkedList<T>::empty()
{
    return (this->m_size == 0);
}

template <typename T>
size_t LinkedList<T>::size() const noexcept
{
    return this->m_size;
}

template <typename T>
void LinkedList<T>::clear() noexcept
{
    // Need to be Implemented
}

template <typename T>
void LinkedList<T>::push_back(const T &value)
{
    // Need to be Implemented
    Node *new_node = new Node(value);
    // if list is empty
    if (this->m_size == 0)
    {
        this->mp_head = new_node;
        this->mp_tail = new_node;
        this->m_size++;
        return;
    }

    // if list is not empty
    new_node->mp_next = nullptr;
    new_node->mp_previous = this->mp_tail;
    this->mp_tail->mp_next = new_node;
    this->mp_tail = new_node;
    this->m_size++;
}

template <typename T>
void LinkedList<T>::pop_back()
{
    // Need to be Implemented
}

template <typename T>
void LinkedList<T>::pop_front()
{
    // Need to be Implemented
}

template <typename T>
void LinkedList<T>::push_front(const T &value)
{
    // Need to be Implemented
}

template <typename T>
T &LinkedList<T>::front()
{
    return this->mp_head->m_data;
}

template <typename T>
const T &LinkedList<T>::front() const
{
    return this->mp_head->m_data;
}

template <typename T>
T &LinkedList<T>::back()
{
    return this->mp_tail->m_data;
}

template <typename T>
const T &LinkedList<T>::back() const
{
    return this->mp_tail->m_data;
}
