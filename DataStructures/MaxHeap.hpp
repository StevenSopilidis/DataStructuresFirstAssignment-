#include <iostream>
#include "../Errors/OutOfMemory.h"
#include "../Errors/OutOfBounds.h"

#pragma once
namespace DataStructures
{
    template <typename T>
    class MaxHeap
    {
    private:
        unsigned int _maxSize;
        unsigned int _currentSize;
        T* _heap; // array that will be used to implement the heap
    public:
        MaxHeap(unsigned int maxSize)
        {
            _heap = new T[1 + maxSize];
            _maxSize = maxSize;
            _currentSize = 0;
        }

        // function for checking if the heap is empty
        inline bool isEmpty() { return _currentSize == 0; }

        // func for inserting an Element into the heap
        // @param el: Element to be inserted
        MaxHeap<T>* Insert(const T& el)
        {
            if (_currentSize == _maxSize)
                throw Errors::OutOfMemory();
            int i = ++_currentSize;
            while (i != 1 && el > _heap[i/2]) {
                _heap[i] = _heap[i/2];
                i /= 2; 
            }
            _heap[i] = el;
            return this;
        }

        // deletes max element of heap
        // @paramm el: return deleted element via parameter
        MaxHeap<T>* DeleteMax(T& el)
        {
            if (_currentSize == 0)
                throw Errors::OutOfMemory();
            el = _heap[1];
            T y = _heap[_currentSize--];
            int i = 1, ci = 2;
            while (ci <= _currentSize) {
                if (ci < _currentSize && _heap[ci] < _heap[ci+1]) ci++;
                if (y >= _heap[ci]) break;
                _heap[i] = _heap[ci];
                i = ci; ci *= 2;
            }
            _heap[i] = y;
            return this;
        }
        
        // method initializing max heap from array
        // @param a: array to initialize from
        // @param size: current size of array
        // @param ArraySize: maxSize of array
        void Initialize(T a[], int size,int ArraySize)
        {
            delete [] _heap;
            _heap = a;
            _currentSize = size;
            _maxSize = ArraySize;
            for (int i = _currentSize/2; i >= 1; i--) {
                T y = _heap[i];
                int c = 2*i;
                while (c <= _currentSize) {
                    if (c < _currentSize && _heap[c] < _heap[c+1]) c++;   
                    if (y >= _heap[c]) break;
                    _heap[c/2] = _heap[c];
                    c *= 2;
                }
                _heap[c/2] = y;
            }
        }

        void Print()
        {
            for (int i = 1; i <= _currentSize; i++)
            {
                std::cout << _heap[i] << std::endl;
            }
            
        }

        ~MaxHeap()
        {
            delete []_heap;
        }
    };
} // namespace 
