#pragma once

#include <iostream>

template <typename T>
class MaxHeap
{
private:
    T *heapArray;
    int capacity;
    int heapSize;

    void resize();
    void swap(T &, T &);

public:
    MaxHeap();
    ~MaxHeap();

    void insert(T);
    T extractMax();
    void print();
};

template <typename T>
MaxHeap<T>::MaxHeap()
{
    capacity = 10;
    heapArray = new T[capacity];
    heapSize = 0;
}

template <typename T>
MaxHeap<T>::~MaxHeap()
{
    delete[] heapArray;
}

template <typename T>
void MaxHeap<T>::resize()
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
void MaxHeap<T>::swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void MaxHeap<T>::insert(T data)
{
    if (heapSize == capacity)
    {
        resize();
    }

    heapSize++;

    heapArray[heapSize] = data;

    // heapify up
    int i = heapSize;
    while (i > 1 && heapArray[i] > heapArray[i / 2])
    {
        swap(heapArray[i], heapArray[i / 2]);
        i /= 2;
    }
}

template <typename T>
T MaxHeap<T>::extractMax()
{
    if (heapSize == 0)
    {
        std::cout << "Heap is empty" << std::endl;
        return -1;
    }

    T max = heapArray[1];
    heapArray[1] = heapArray[heapSize];
    heapSize--;

    // heapify down
    int i = 1;
    while (i < heapSize)
    {
        if (2 * i < heapSize && heapArray[i] < heapArray[2 * i] && heapArray[2 * i] > heapArray[2 * i + 1])
        {
            swap(heapArray[i], heapArray[2 * i]);
            i = 2 * i;
        }
        else if (2 * i + 1 < heapSize && heapArray[i] < heapArray[2 * i + 1] && heapArray[2 * i] < heapArray[2 * i + 1])
        {
            swap(heapArray[i], heapArray[2 * i + 1]);
            i = 2 * i + 1;
        }
        else
        {
            break;
        }
    }

    return max;
}

template <typename T>
void MaxHeap<T>::print()
{
    for (int i = 1; i <= heapSize; i++)
    {
        std::cout << heapArray[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    MaxHeap<int> heap;

    heap.insert(5);
    heap.insert(3);
    heap.insert(17);
    heap.insert(10);
    heap.insert(84);
    heap.insert(19);

    heap.print();

    std::cout << std::endl << heap.extractMax() << std::endl;
    std::cout << std::endl << heap.extractMax() << std::endl;
    std::cout << std::endl << heap.extractMax() << std::endl;
    std::cout << std::endl << heap.extractMax() << std::endl;
    std::cout << std::endl << heap.extractMax() << std::endl;
    std::cout << std::endl << heap.extractMax() << std::endl;
    std::cout << std::endl << heap.extractMax() << std::endl;

    heap.print();





}