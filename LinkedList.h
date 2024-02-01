#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>

template <typename U>
class Node;

template <typename LinkedList>
class LinkedListIterator;

template <typename T>
class LinkedList
{
    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using iterator = LinkedListIterator<value_type>;

public:
    LinkedList();
    ~LinkedList();
    bool empty();
    size_t size() const noexcept;
    void clear() noexcept;
    void push_back(const T &value);
    void pop_back();
    void pop_front();
    void push_front(const T &value);
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;

private:
    size_t m_size;
    Node<T> *mp_head;
    Node<T> *mp_tail;
};

template <typename U>
class Node
{
    template <typename T>
    friend class LinkedList;

public:
    Node();
    Node(const U &_value);
    Node(const U &_value, U *_next, U *_previous);
    ~Node();

private:
    U m_data;
    Node<U> *mp_next;
    Node<U> *mp_previous;
};

#include "LinkedList.cpp"

#endif // LINKED_LIST_H
