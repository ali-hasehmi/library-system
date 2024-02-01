#include "queue.h"
#include <cstdlib>
template<typename T>
queue<T>::queue(int argMaxLength) : frontIndex(-1),
                                    backIndex(-1),
                                    size(argMaxLength),
                                    elementCount(0) {
    dataArray = new T[argMaxLength];
}

template<typename T>
bool queue<T>::isEmpty() {
    return !elementCount;
}

template<typename T>
T *queue<T>::front() {
    return &dataArray[frontIndex];
}

template<typename T>
void queue<T>::enqueue(const T& argData) {
    if (elementCount == size) {
        // queue full
        T* newArray = (T*) realloc(dataArray,sizeof(T)*size*2);
        if(newArray == nullptr){
          std::cout << "realloc failed";
        }
        dataArray = newArray;
        delete[] newArray;
    } else {
        dataArray[(++backIndex) % size] = argData;
        ++elementCount;
    }
}

template<typename T>
T queue<T>::dequeue() {
    if (isEmpty()) {
        std::cout << "QUEUE IS EMPTY";
        return -1;
    } else {
        T front = dataArray[frontIndex];
        ++frontIndex;
        --elementCount;
        return front;
    }
}

template<typename T>
queue<T>::~queue() {
    delete[] dataArray;
}
