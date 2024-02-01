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
LinkedList<T>::LinkedList()
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
typename LinkedList<T>::iterator LinkedList<T>::begin()
{
    return iterator(this->mp_head);
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::end()
{
    return iterator(nullptr);
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
void LinkedList<T>::push_back(const_reference value)
{
    // Need to be Implemented
    Node<T> *new_node = new Node<T>(value);
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
void LinkedList<T>::push_front(const_reference value)
{
    // Need to be Implemented
}

template <typename T>
typename LinkedList<T>::reference LinkedList<T>::front()
{
    return this->mp_head->m_data;
}

template <typename T>
typename LinkedList<T>::const_reference LinkedList<T>::front() const
{
    return this->mp_head->m_data;
}

template <typename T>
typename LinkedList<T>::reference LinkedList<T>::back()
{
    return this->mp_tail->m_data;
}

template <typename T>
typename LinkedList<T>::const_reference LinkedList<T>::back() const
{
    return this->mp_tail->m_data;
}

template <typename LinkedList>
LinkedListIterator<LinkedList>::LinkedListIterator(Node<value_type> *_ptr)
    : mp_ptr(_ptr)
{
}

template <typename LinkedList>
inline bool LinkedListIterator<LinkedList>::operator==(const LinkedListIterator &_itr) const
{
    return this->mp_ptr == _itr.mp_ptr;
}

template <typename LinkedList>
bool LinkedListIterator<LinkedList>::operator!=(const LinkedListIterator &_itr) const
{
    return this->mp_ptr != _itr.mp_ptr;
}

template <typename LinkedList>
LinkedListIterator<LinkedList> &LinkedListIterator<LinkedList>::operator++()
{
    this->mp_ptr = this->mp_ptr->mp_next;
    return *(this);
}

template <typename LinkedList>
LinkedListIterator<LinkedList> LinkedListIterator<LinkedList>::operator++(int)
{
    LinkedListIterator<LinkedList> tmp(*this);
    ++(*this);
    return tmp;
}

template <typename LinkedList>
LinkedListIterator<LinkedList> &LinkedListIterator<LinkedList>::operator--()
{
    this->mp_ptr = this->mp_ptr->mp_previous;
    return *this;
}

template <typename LinkedList>
LinkedListIterator<LinkedList> LinkedListIterator<LinkedList>::operator--(int)
{
    LinkedListIterator<LinkedList> tmp(*this);
    --(*this);
    return tmp;
}

template <typename LinkedList>
typename LinkedListIterator<LinkedList>::const_reference LinkedListIterator<LinkedList>::operator*() const
{
    return this->mp_ptr->m_data;
}

template <typename LinkedList>
typename LinkedListIterator<LinkedList>::reference LinkedListIterator<LinkedList>::operator*()
{
    return this->mp_ptr->m_data;
}

template <typename LinkedList>
typename LinkedListIterator<LinkedList>::pointer LinkedListIterator<LinkedList>::operator->()
{
    return &(this->mp_ptr->m_data);
}

template <typename LinkedList>
typename LinkedListIterator<LinkedList>::const_pointer LinkedListIterator<LinkedList>::operator->() const
{
    return &(this->mp_ptr->m_data);
}
