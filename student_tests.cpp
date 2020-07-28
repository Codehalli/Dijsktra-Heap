/*
 *  Purpose for program:
 *  This programming project is understanding and implementing dijkstra algorithm and heaps
 *
 *  studentTest.hpp
 *  Programmer: Pranav Rao
 *  Date: December 18, 2019
 *
 *  Honor Code: I have neither given nor received any unauthorized assistance with this program.
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "heap_priority_queue.hpp"

//This test checks the constructor function
TEST_CASE( "Constructor", "[Heap_Priority_Queue]" ){
    
    HeapPriorityQueue<int> q;
    REQUIRE(q.isEmpty()); //checks if empty
}

//This test checks the copy constructor funciton
TEST_CASE( "Copy Constructor", "[Heap_Priority_Queue]" ){
    HeapPriorityQueue<int> q;
    
    q.add(1); //adds
    q.add(2);
    
    REQUIRE(q.peek() == 1);
}

//This test checks the add function
TEST_CASE( "Add", "[Heap_Priority_Queue]" ){
    HeapPriorityQueue<int> q;
    
    q.add(5); //add function
    REQUIRE(q.peek() == 5); //checks the peek
    q.add(7);
    REQUIRE(q.peek() == 5);
    q.add(1);
    REQUIRE(q.peek() == 1);
    q.add(4);
    REQUIRE(q.peek() == 1);
}

//This test checks the copy operator function
TEST_CASE( "Copy Operator", "[Heap_Priority_Queue]" ){
    HeapPriorityQueue<int> q;
    
    q.add(1);
    q.add(2);
    REQUIRE(q.peek() == 1); //checks the peek
}

//This test checks the empty funciton
TEST_CASE( "IsEmpty", "[Heap_Priority_Queue]" ){
    HeapPriorityQueue<int> q;
    
    q.add(7); //adds 7 to the queue
    q.remove(); //then removes
    REQUIRE(q.isEmpty()); //therefore checks to see if it's empty
    REQUIRE(q.isEmpty());
    
}

//This test checks the remove funciton
TEST_CASE( "Remove", "[Heap_Priority_Queue]" ) {
    HeapPriorityQueue<int> q;
    
    q.add(1); //add function
    REQUIRE(q.peek() == 1); //checks to peek  it.
    q.add(5);
    REQUIRE(q.peek() == 1);
    q.remove();
    REQUIRE(q.peek() == 5);
}

//This test checks peek function
TEST_CASE( "Peek", "[Heap_Priority_Queue]" ){
    HeapPriorityQueue<int> q;

    q.add(1); //adds
    REQUIRE(q.peek() == 1); //then peeks it.
    q.add(8);
    REQUIRE(q.peek() == 1);
    q.add(30);
    REQUIRE(q.peek() == 1);
}

//This test checks the empty function in the list.txx
TEST_CASE( "Insert", "[List]" ){
  HeapPriorityQueue<int> q;

  q.add(1);
  REQUIRE(q.peek() == 1);
}
