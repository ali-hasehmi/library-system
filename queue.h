
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>


template<typename T>
class queue {
    T *dataArray;
    int frontIndex;
    int backIndex;
    int size;
    int elementCount;
public:
    queue(int argMaxLength);
    queue();

    bool isEmpty();

    T *front();

    T dequeue();

    void enqueue(const T& argData);

    ~queue();
};

#include "queue.cpp"
#endif //DS_QUEUE_HPP
