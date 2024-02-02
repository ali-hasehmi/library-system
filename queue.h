
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

#include "datastream.h"

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

    void enqueue(const T &argData);

    ~queue();

    template<typename U>
    friend outputDataStream &operator<<(outputDataStream &osd, const queue<U> &_q);

    template<typename U>
    friend inputDataStream &operator>>(inputDataStream &isd, queue<U> &_q);
};

#include "queue.cpp"

#endif //DS_QUEUE_HPP


