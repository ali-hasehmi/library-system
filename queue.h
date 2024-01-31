
#ifndef DSPROJECT_QUEUE_H
#define DSPROJECT_QUEUE_H

#include <iostream>
#include <array>

template<typename T>
class queue {
    T *dataArray;
    int frontIndex;
    int backIndex;
    int size;
    int elementCount;
public:
    queue(int argMaxLength);

    bool isEmpty();

    T *front();

    T dequeue();

    void enqueue(T argData);

    ~queue();
};


#endif //DS_QUEUE_HPP
