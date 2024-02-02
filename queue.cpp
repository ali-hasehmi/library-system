#include "queue.h"
#include <cstdlib>

template <typename T>
queue<T>::queue(int argMaxLength) : frontIndex(-1),
                                    backIndex(-1),
                                    size(argMaxLength),
                                    elementCount(0)
{
    dataArray = new T[argMaxLength];
}

template <typename T>
queue<T>::queue() : frontIndex(-1),
                    backIndex(-1),
                    size(1),
                    elementCount(0)
{
    dataArray = new T[size];
}

template <typename T>
int queue<T>::capacity()
{
    return this->size;
}

template <typename T>
int queue<T>::count()
{
    return this->elementCount;
}

template <typename T>
bool queue<T>::isEmpty()
{
    return !elementCount;
}

template <typename T>
T& queue<T>::front()
{
    return dataArray[frontIndex];
}

template <typename T>
void queue<T>::enqueue(const T &argData)
{
    if (elementCount == size)
    {
        // queue full
        /*T* newArray = (T*) realloc(dataArray,sizeof(T)*size*2);
        if(newArray == nullptr){
          std::cout << "realloc failed";
        }
        dataArray = newArray;*/
        dataArray = (T *)realloc(dataArray, sizeof(T) * size * 2);
        size *= 2;
    }
    dataArray[(++backIndex) % size] = argData;
    ++elementCount;
}

template <typename T>
T& queue<T>::dequeue()
{
    if (isEmpty())
    {
        std::cout << "QUEUE IS EMPTY";
        throw -1;
    }
    else
    {
        T& front = dataArray[++frontIndex];

        --elementCount;
        return front;
    }
}

template <typename T>
queue<T>::~queue()
{
    delete[] dataArray;
}

template <typename U>
outputDataStream &operator<<(outputDataStream &osd, const queue<U> &_q)
{
    osd << _q.size << _q.elementCount << _q.frontIndex << _q.backIndex;
    for (int i = 0; i < _q.elementCount; ++i)
    {
        osd << _q.dataArray[(i + _q.frontIndex +1) % _q.size];
    }
    return osd;
}

template <typename U>
inputDataStream &operator>>(inputDataStream &isd, queue<U> &_q)
{
    isd >> _q.size >> _q.elementCount >> _q.frontIndex >> _q.backIndex;
    _q.dataArray = new U[_q.size];
    for (int i = 0; i < _q.elementCount; ++i)
    {
        isd >> _q.dataArray[(i + _q.frontIndex +1) % _q.size];
    }
    return isd;
}
