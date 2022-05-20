#include "../Errors/OutOfBounds.h"
#include <iostream>

#pragma once
namespace DataStructures
{
    struct HistogramItem
    {
        int number;
        int count;
    };

    std::ostream& operator<<(std::ostream& os, const HistogramItem& h)
    {
        return os << "Number: " <<  h.number << ", Count: " << h.count; 
    }
    
    bool operator < (const HistogramItem& h1,const HistogramItem& h2)
    {
        return h1.number < h2.number;
    }



    template <typename T>
    struct Node
    {
        T data;
        struct Node<T>* next;
    };

    template <typename T>
    class LinkedList
    {
    private:
        struct Node<T>* _head = nullptr; // root of the LinkedList
        unsigned int _length = 0;// length of the linked list
    public:
        inline int Length() const { return _length; } 
        inline bool IsEmpty() const { return _head==nullptr; }

        // method for inserting an element at LinkedList
        // @param pos: after which pos the element will be inserted
        // @param data: pos of the data we are insertinng
        LinkedList<T>* Insert(const T& data,unsigned int pos)
        {
            if(pos < 0 || pos >  _length)
                throw new Errors::OutOfBounds();
            // new head
            if(pos == 0)
            {
                struct Node<T>* tmp = _head;
                _head = new struct Node<T>();
                _head->data = data;
                _head->next = tmp;
                _length++;
                return this;
            }
            struct Node<T>* current = _head;
            int i = 1;
            while (i < pos)
            {
                current = current->next;
                i++;
            }
            struct Node<T>* newItem = new struct Node<T>();
            newItem->data = data;
            newItem->next = current->next;
            current->next = newItem;
            _length++;
            return this;
        };
        //method  for removing an element from LinkedList
        // @param data: returs removed data via this parameter
        // @param pos: position of element to remove
        LinkedList<T>* Remove(T& data, unsigned int pos)
        {
            if(this->IsEmpty() || _length <  pos || pos == 0)
                throw new Errors::OutOfBounds();
            // remove head
            if(pos == 1)
            {
                data = _head->data;
                _head = _head->next;
                _length--;
                return this;
            }
            struct Node<T>* current = _head;
            int i = 2; 
            while(i  < pos)
            {
                current = current->next;
                i++; 
            }
            // if we are at the end of the list
            if(pos == _length)
            {
                data = current->next->data;
                current->next = nullptr;
            }else {
                data = current->next->data;
                current->next =  current->next->next;
            }
            _length--;
            return this;
        }

        // Method for returning an element at certain position
        // returns item at certain position
        // @param pos: position of the element
        T At(unsigned int pos) const
        {
            if(pos < 1 || pos > _length)
                throw new Errors::OutOfBounds();
            struct Node<T>* current = _head;
            int i = 1;
            while(i < pos)
            {
                current =  current->next;
                i++;
            }
            return current->data;
        }

        // returns a int index of element (1 based index)
        // if item does not exist returns -1
        // @param item: item to look for
        int Find(const T& item) const
        {
            struct Node<T>* current = _head;
            int index = 1;
            while(current != nullptr && current->data != item)
            { 
                current = current->next;
                index++;
            }
            return current != nullptr? index : -1;
        }

        void Print()
        {
            Node<T> *current = _head;
            while(current != nullptr)
            {
                std::cout << current->data << std::endl;
                current = current->next;
            } 
        }

        // method for sorting LinkedList at ascending order
        void Sort()
        {
            Node<T>* cur1 = _head;
            Node<T>* cur2 = _head;
            for (int i = 0; i < _length; i++) {
                for (int j = 0; j < _length - 1; j++) {
                    if (cur1->data < cur2->data) {
                        T temp = cur1->data;
                        cur1->data = cur2->data;
                        cur2->data = temp;
                    }
                    cur2 = cur2->next;
                }
                cur2 = _head;
                cur1 = _head->next;
                for (int k = 0; k < i; k++) {
                    cur1 = cur1->next;
                }
            }
        }

        ~LinkedList()
        {
            Node<T>* current = _head;
            while(current != nullptr)
            {
                delete current;
                current = current->next;
            }
        }
    };
}