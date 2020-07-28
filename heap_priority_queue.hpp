/*
 *  Purpose for program:
 *  This programming project is understanding and implementing dijkstra algorithm and heaps
 *
 *  HeapPriorityQueue.hpp
 *  Programmer: Pranav Rao
 *  Date: December 18, 2019
 *
 *  Honor Code: I have neither given nor received any unauthorized assistance with this program.
 */
#ifndef _HEAP_PRIORITY_QUEUE_H
#define _HEAP_PRIORITY_QUEUE_H

#include <stdexcept>
#include "abstract_priority_queue.hpp"
#include <new>

template <typename T>
class HeapPriorityQueue: public AbstractPriorityQueue<T> //public members
{
public:
    
    HeapPriorityQueue(); // This function is the constructor
    ~HeapPriorityQueue(); //This function is the destructor
    HeapPriorityQueue( HeapPriorityQueue & x); //This function is the copy constructor
    HeapPriorityQueue& operator=(HeapPriorityQueue x); //This funtion is the Copy assignment
    
    
    void add(const T& item) throw(std::bad_alloc); //This function add's the to th queue

    void remove() throw(std::range_error); //This function removes from the queue
    
    bool isEmpty() const; //This function returns if the the queue is empty
    
    T peek() const throw(std::range_error); //This  throws an error if the condition is not met
private: //private members
   
    //private variables declared
    T * items; //this is the array
    std::size_t itemCount; //this variable determines the count in the variable
    std::size_t maxItems; //this variable is the most amount number of items in the array
    
    //feel free to define additional helper methods
    
    void swap(const int j1, const int j2); //swap the variables
    
    int getLocation(const int j); //get the position of the nodes
    
    void constructHeap(const int j); //build the heap
    
    int getRight(const int j);//for the right child
    int getLeft(const int j); //for the left child
};

#include "heap_priority_queue.txx"
#endif
