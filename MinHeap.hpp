#pragma once

#include <iostream>

template <typename T>
class MinHeap
{
private:
    T *heapArray;
    int capacity;
    int heapSize;

    void resize();
    void swap(T &, T &);

public:
    MinHeap();
    ~MinHeap();

    void insert(T);
    T extractMin();
    void print();
};

template <typename T>
MinHeap<T>::MinHeap()
{
    capacity = 10;
    heapArray = new T[capacity];
    heapSize = 0;
}
template <typename T>
MinHeap<T>::~MinHeap()
{
    delete[] heapArray;
}

template <typename T>
void MinHeap<T>::resize()
{
    T *temp = new T[capacity * 2];
    for (int i = 0; i < capacity; i++)
    {
        temp[i] = heapArray[i];
    }
    delete[] heapArray;
    heapArray = temp;
    capacity *= 2;
}

template <typename T>
void MinHeap<T>::swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void MinHeap<T>::insert(T data)
{
    if (heapSize == capacity)
    {
        resize();
    }

    heapSize++;

    heapArray[heapSize] = data;

    // heapify up
    int i = heapSize;
    while (i > 1 && heapArray[i] < heapArray[i / 2])
    {
        swap(heapArray[i], heapArray[i / 2]);
        i /= 2;
    }
}

template <typename T>
T MinHeap<T>::extractMin()
{
    if (heapSize == 0)
    {
        std::cout << "Heap is empty" << std::endl;
        return -1;
    }

    T min = heapArray[1];
    heapArray[1] = heapArray[heapSize];
    heapSize--;

    // heapify down
    int i = 1;
    while (i < heapSize)
    {
        if (2 * i < heapSize && heapArray[i] > heapArray[2 * i])
        {
            swap(heapArray[i], heapArray[2 * i]);
            i = 2 * i;
        }
        else if (2 * i + 1 < heapSize && heapArray[i] > heapArray[2 * i + 1])
        {
            swap(heapArray[i], heapArray[2 * i + 1]);
            i = 2 * i + 1;
        }
        else
        {
            break;
        }
    }

    return min;
}

template <typename T>
void MinHeap<T>::print()
{
    for (int i = 1; i <= heapSize; i++)
    {
        std::cout << heapArray[i] << " ";
    }
    std::cout << std::endl;
}
