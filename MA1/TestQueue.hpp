#pragma once
#include "Queue.hpp"

/*
Test ID: Test Enqueue
Unit: queue::enqueue
Description: This function will test the enqueue by instantiating a empty list, inserting into that empty
list, and then inserting a second function into that empty list
Test Data: intitial: null, 6, 10
Precondition: List is empty
Postcondition: list has 2 elements inside list, both accessible
Expected Result:
Actual Result:
Test Condition: Valid
*/
void test_enqueue(void);
/*
Test ID: Test Dequeue
Unit: queue::dequeue
Description: WIll create a list of size 3, and then begin dequeuing until the list is empty
Test Data: 0 
Precondition: List has size 3
Postcondition: List is empty
Expected Result: list should be empty
Actual Result:
Test Condition: vaild
*/
void test_dequeue(void);

/*
Test ID: Test peek
Unit: queue::peek
Description: Will create an empty list, verify that peak is working, then insert an element into list,
and verify it's validity
Test Data: inserting 6 into list
Precondition: list is empty
Postcondition: list has 1 element
Expected Result: peek should return null then 6
Actual Result:
Test Condition:
*/
void test_peek();
/*
Test ID: Test Size
Unit: queue::size
Description: will check if the function will return the correct list size
Test Data: list will have 3 elements in it, all of which are irrelevent
Precondition: list is empty
Postcondition: list has 3 elements and the size variable reflects that fact
Expected Result:
Actual Result:
Test Condition:
*/
void test_size();
/*
Test ID: Test Empty Function
Unit: Queue::isEmpty
Description: The function creates an instantiation of a queue. Then it tests to make sure that the value that is returned is accurate.
it will check an empty list and a non empty list.
Test Data: size = 0
Precondition: The list is empty
Postcondition: The list has one element
Expected Result: The Function should return true for the first test and false for the second test
Actual Result: True, false
Test Condition: passed
*/
void test_isEmpty();
/*
Test ID: Test isFull
Unit: queue::isFull
Description: Will create an empty list, check if isFull works, then will fill the mix until overflow and then try again
Test Data: How much data the list can hold
Precondition: list is empty
Postcondition: list is full
Expected Result: will return that the list was full at the appropriate times
Actual Result:
Test Condition: vailid
*/
void test_isFull();

//Runs all of the tests in one place
void runAllTests(void);

//#include "TestQueue.cpp"