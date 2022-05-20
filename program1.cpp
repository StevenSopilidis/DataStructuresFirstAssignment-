#include <iostream>
#include "./Utils/Utils.h"
#include "./DataStructures/LinkedList.hpp"

using namespace DataStructures;

// upper and lower bounds of the random number that will be generated
#define UPPER_BOUND 100
#define LOWER_BOUND 0

int main()
{
    // get the number of elements to inser
    unsigned int number;
    std::cout << "How many numbers to insert at L list: ";
    std::cin >> number; 
    std::cout << "\n";
    if(!std::cin.good())
    {
        std::cout << "Invalid number for elements inserted" << std::endl;
        return -1;
    }

    try
    {
        // create the L list
        LinkedList<int>* L = new LinkedList<int>();
        for (int i=0; i<number;i++)
        {
            int randomNumber = Utils::GetRandomInt(LOWER_BOUND,UPPER_BOUND);
            L->Insert(randomNumber, randomNumber);
        }

        // create the histograrm
        LinkedList<HistogramItem> *histogram = new LinkedList<HistogramItem>();
        while(!L->IsEmpty())
        {
            int item = L->At(1);
            struct HistogramItem *h = new struct HistogramItem();
            h->number = item;
            h->count = 1;
            int pos = 1;
            L->Remove(item, 1);
            while (true)
            {
                pos = L->Find(h->number);
                if(pos == -1)
                {
                    break;
                }
                h->count++;
                L->Remove(item, pos);
            }
            // insert new item in correct spot to keep ascending order
            histogram->Insert(*h, histogram->Length());
        }

        // sort histogram
        histogram->Sort();
        histogram->Print();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
}