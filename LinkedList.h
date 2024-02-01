#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>
#include "datastream.h"

template <typename U>
class Node;

template <typename LinkedList>
class LinkedListIterator;

template <typename T>
class LinkedList
{

public:
    using value_type = T;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using reference = value_type &;
    using const_reference = const value_type &;
    using iterator = LinkedListIterator<LinkedList<value_type>>;
    LinkedList();
    ~LinkedList();
    iterator begin();
    iterator end();
    bool empty();
    size_t size() const noexcept;
    void clear() noexcept;
    void push_back(const_reference value);
    void pop_back();
    void pop_front();
    void push_front(const_reference value);
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;
    template <typename U>
    friend outputDataStream &operator<<(outputDataStream &ods, const LinkedList<U> &_Dll);

    template <typename U>
    friend inputDataStream &operator>>(inputDataStream &ids, LinkedList<U> &_Dll);

private:
    size_t m_size;
    Node<value_type> *mp_head;
    Node<value_type> *mp_tail;
};

template <typename LinkedList>
class LinkedListIterator
{

public:
    using value_type = typename LinkedList::value_type;
    using reference = typename LinkedList::reference;
    using const_reference = typename LinkedList::const_reference;
    using pointer = typename LinkedList::pointer;
    using const_pointer = typename LinkedList::const_pointer;
    LinkedListIterator(Node<value_type> *_ptr);
    bool operator==(const LinkedListIterator &_itr) const;
    bool operator!=(const LinkedListIterator &_itr) const;
    LinkedListIterator &operator++();
    LinkedListIterator operator++(int);
    LinkedListIterator &operator--();
    LinkedListIterator operator--(int);
    const_reference operator*() const;
    reference operator*();
    pointer operator->();
    const_pointer operator->() const;

private:
    Node<value_type> *mp_ptr;
};
template <typename U>
class Node
{
    template <typename T>
    friend class LinkedList;
    template <typename LinkedList>
    friend class LinkedListIterator;

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
