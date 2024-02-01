#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename U>
class Node;

template <typename T>
class LinkedList
{

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
    friend class LinkedList;

public:
    Node();
    Node(const U &_value);
    Node(const U &_value, U *_next, U *_previous);
    ~Node();

private:
    U m_data;
    U *mp_next;
    U *mp_previous;
};

#include "LinkedList.cpp"

#endif // LINKED_LIST_H

