#include <iostream>
#include "Utils/Utils.h"
#include "./DataStructures/MinHeap.hpp"
#include "./DataStructures/MaxHeap.hpp"

using namespace DataStructures;

int main()
{
    // get user input
    unsigned int N; //size of heap_min and heap_max
    std::cout << "Give value of size of heap_min and heap_max: ";
    std::cin >> N;
    std::cout << "\n";
    if(!std::cin.good())
    {
        std::cout << "Invalid value for heap_min and heap_max arrays given" << std::endl;
        return -1;
    }
    
    try
    {
        // allocate heap_min and set the random values
        float* heap_min = new float[N];
        for (int i = 0; i < N; i++)
        {
            // replace later with my own generator from Utils
            heap_min[i] = Utils::GetRandomFloat();
        }
        // allocate heap_max and copy all the elements
        float* heap_max = new float[N];
        for (int i = 0; i < N; i++)
        {
            heap_max[i] = heap_min[i];
        }

        // allocate the two heaps
        MinHeap<float>* minHeap = new MinHeap<float>(N); 
        MaxHeap<float>* maxHeap = new MaxHeap<float>(N); 

        // will be replaced by function call later
        maxHeap->Initialize(heap_max, N, N);
        minHeap->Initialize(heap_min, N, N);
        
        // implement the algorithm for min heap
        float minHeapSum = 0;
        while(true)
        {
            float num1;
            minHeap->DeleteMin(num1);
            if(minHeap->isEmpty())
            {
                minHeapSum = num1;
                break;
            }
            float num2;
            minHeap->DeleteMin(num2);
            minHeap->Insert(num1 + num2);
        }
        std::cout << "Sum of min heap: " << minHeapSum << std::endl;
        
        //implement the algorithm max min heap
        float maxHeapSum = 0;
        while(true)
        {
            float num1;
            maxHeap->DeleteMax(num1);
            if(maxHeap->isEmpty())
            {
                maxHeapSum = num1;
                break;
            }
            float num2;
            maxHeap->DeleteMax(num2);
            maxHeap->Insert(num1 + num2);
        }
        std::cout << "Sum of max heap: " << maxHeapSum << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}