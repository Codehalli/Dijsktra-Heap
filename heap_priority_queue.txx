/*
 *  Purpose for program:
 *  This programming project is understanding and implementing dijkstra algorithm and heaps
 *
 *  HeapPriorityQueue.txx
 *  Programmer: Pranav Rao
 *  Date: December 18, 2019
 *
 *  Honor Code: I have neither given nor received any unauthorized assistance with this program.
 */
#include "heap_priority_queue.hpp"

//This function is the constructor funtion
template <typename T>
HeapPriorityQueue<T>::HeapPriorityQueue():itemCount(0), maxItems(10){
    items = new T[maxItems]; //setting new items to the max
    
}

//This function is the destructor
template <typename T>
HeapPriorityQueue<T>::~HeapPriorityQueue(){
    delete [] items; //deleting the items
    
}

//This function is the copy constructor
template<typename T>
HeapPriorityQueue<T>::HeapPriorityQueue( HeapPriorityQueue& x )
{
    int i = 0; //declaring and initalizing the varialbes
    int j = 10;
    itemCount = i; //set the item and and max item
    maxItems = j;
    items = new T[maxItems];
    
    while(!x.isEmpty()) //while loop to check if it is emtpy
    {
        add(x.peek());
        
        x.remove(); //remove function for the parameter variable
    }
}

//This function is the copy operator
template<typename T>
HeapPriorityQueue<T>& HeapPriorityQueue<T>::operator=(HeapPriorityQueue<T> x) {
    
    int i = 0; //declaring and initalizing the varialbes
    int j = 10;
    itemCount = i; //set the item and and max item
    maxItems = j;
    items = new T[maxItems];
    
    while(!x.isEmpty()) //while loop to check if it is emtpy
    {
        add(x.peek());
        x.remove(); //remove function for the parameter variable
    }
}

//This function checks to see if queue is empty
template <typename T>
bool HeapPriorityQueue<T>::isEmpty() const {
    int i= 0; //declaring and initalizing the varialbes
    return(itemCount == i); //item count to i;
}

//This function adds to the queue
template <typename T>
void HeapPriorityQueue<T>::add(const T& item) throw(std::bad_alloc) {
    
    if(itemCount == maxItems) //conditon if max count = to item count
    {
        T* dum = items; //check the dum variables
        items = new T[maxItems*2];
        
        int i=0; //declaring and initalizing the varialbes
        while(i<maxItems) //while loop conditon for checking the max items
        {
            items[i] = dum[i];
            i++; //increment
        }

        delete [] dum; //delete the dummy variable
        maxItems *= 2;
        dum = nullptr; //set it to nullptr
    }
    
    if(itemCount == 0) //check if item count is 0
    {
        items[0] = item;
    }
    else
        {
            int indexN = itemCount; //set the index N and P
            items[indexN] = item;  //so we can swap it later
            int indexP = getLocation(indexN);
            
            while(items[indexN] < items[indexP])
            {
                swap(indexN,indexP);
                indexN = indexP;
                indexP = getLocation(indexN); //get the position of N after the swap
            }
        }
    
    itemCount++; //increment
    
}

//This function gets the location of the child
template <typename T>
int HeapPriorityQueue<T>::getLocation(const int j)
{
    int k = (j-1)/2; //declaring the setting the equation to
    return  k; //return k
}

//This function swaps the variables
template <typename T>
void HeapPriorityQueue<T>::swap(const int j1, const int j2)
{
    T dum; //se the temporary variable
    dum = items[j2];
    items[j2] = items[j1];
    items[j1] = dum; //dum variable
}

//This function removes from the queue
template <typename T>
void HeapPriorityQueue<T>::remove() throw(std::range_error) {
    
    int k= 0;
    
    if(itemCount == k) //if contion to return if the queue is empty
    {
        throw std::range_error("Empty Queue"); //empty queue
    }
    if(itemCount > k)
    {
       
        items[k] = items[itemCount - 1];
        
        constructHeap(k);

        itemCount--; //decrement the queue
    }
}

//This function throws error if not in the queue
template <typename T>
T HeapPriorityQueue<T>::peek() const throw(std::range_error) {
    if(itemCount == 0) //if contion to return if the queue is 0
    {
        throw std::range_error("Empty Queue");
    }
    else
    {
        return items[0]; //return the first item
    }
}

//This function helps move the node index
template <typename T>
void HeapPriorityQueue<T>::constructHeap(const int j) //build the heap
{
    
    if(getLeft(j) < itemCount)
    {
        int indexChild = getLeft(j); //get the lef chil
        
        if(getRight(j) < itemCount && items[getRight(j)] < items[getLeft(j)]) {
            indexChild = getRight(j);
        }
        
        if(items[j] > items[indexChild]) {
           
            swap(j,indexChild); //the position of the child
        
            constructHeap(indexChild); //calll the construction heaap
        }
    }
}

//method for the left nod
template <typename T> int HeapPriorityQueue<T>::getLeft(const int j) {
    int k = (2*j+1); //declaring the setting the equation to
    return k; //return k
}

//method for the right node
template <typename T> int HeapPriorityQueue<T>::getRight(const int j) {
    int k = (2*j+2); //declaring the setting the equation to
    return k; //return k
}
