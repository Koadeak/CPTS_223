#pragma once
#include "TestQueue.hpp"

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
void test_enqueue(void)
{
    cout << "Testing Enqueue" << endl;

    queue testQueue;
    int successes = 0;

    testQueue.enqueue(6);

    cout << "Top of list is " << testQueue.peek() << endl;
    if (testQueue.peek() == 6)
    {
        cout << "Test passed for inserting into empty List" << endl;
        successes++;
    }
    else
    {
        cout << "Test failed for inserting into empty List" << endl;
    }

    testQueue.enqueue(10);

    cout << "Top of list is " << testQueue.peek() << endl;
    if (testQueue.peek() == 10 && testQueue.size() == 2)
    {
        cout << "Test passed for inserting into non-empty List" << endl;
        successes++;
    }
    else
    {
        cout << "Test failed for inserting into non-empty List" << endl;
    }

    if (successes == 2)
    {
        cout << "Unit Test passed" << endl;
    }
    else 
    {
        cout << "Unit Test failed" << endl;
    }

    cout << endl;

}

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
void test_dequeue(void)
{
    queue testQueue;
    int successes = 0;

    cout << "Testing dequeue" << endl;

    testQueue.enqueue(1);
    testQueue.enqueue(2);
    testQueue.enqueue(3);

    testQueue.dequeue();
    testQueue.dequeue();
    testQueue.dequeue();
    testQueue.dequeue();

    if (testQueue.isEmpty() == true)
    {
        cout << "Dequeue Unit test passed" << endl;
    }
    else
    {
        cout << "Dequeue Unit test failed" << endl;

    }

}


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
void test_peek()
{
    cout << "Testing Peek" << endl;

    queue testQueue;
    int successes = 0;

     cout << "Top of list is " << testQueue.peek() << endl;
    if (testQueue.peek() == NULL)
    {
        cout << "Test passed for peeking into empty List" << endl;
        successes++;
    }
    else
    {
        cout << "Test failed for peeking into empty List" << endl;
    }

    testQueue.enqueue(6);

    cout << "Top of list is " << testQueue.peek() << endl;
    if (testQueue.peek() == 6)
    {
        cout << "Test passed for peeking into non-empty List" << endl;
        successes++;
    }
    else
    {
        cout << "Test failed for peeking into non-empty List" << endl;
    }


    if (successes == 2)
    {
        cout << "Unit Test passed" << endl;
    }
    else 
    {
        cout << "Unit Test failed" << endl;
    }

    cout << endl;
}

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
void test_size()
{
    queue testQueue;
    int successes = 0;

    cout << "Testing Size" << endl;

    if (testQueue.size() == 0)
    {
        cout << "Size has passed for empty list" << endl;
        successes++;
    }
    else
    {
        cout << "Size returned: " << testQueue.isEmpty() << endl;
        cout << "Size has Failed for empty list" << endl;
    }
    
    testQueue.enqueue(6);

    if (testQueue.isEmpty() == 1)
    {
        cout << "Size has passed for non-empty list" << endl;
        successes++;
    }
    else
    {
        cout << "Size has Failed for empty list" << endl;
    }

    if (successes == 2)
    {
        cout << "Size has passed for both cases!" << endl;
    }
    else
    {
        cout << "Size has failed in one case" << endl;
    }

    cout << endl;
}

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
void test_isEmpty()
{
    queue testQueue;
    int successes = 0;

    cout << "Testing isEmpty" << endl;

    if (testQueue.isEmpty() == true)
    {
        cout << "isEmpty has passed for empty list" << endl;
        successes++;
    }
    else
    {
        cout << "IsEmpty returned: " << testQueue.isEmpty() << endl;
        cout << "isEmpty has Failed for empty list" << endl;
    }
    
    testQueue.enqueue(6);

    if (testQueue.isEmpty() == false)
    {
        cout << "isEmpty has passed for non-empty list" << endl;
        successes++;
    }
    else
    {
        cout << "isEmpty has Failed for empty list" << endl;
    }

    if (successes == 2)
    {
        cout << "isEmpty has passed for both cases!" << endl;
    }
    else
    {
        cout << "isEmpty has failed in one case" << endl;
    }

    cout << endl;
}

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
void test_isFull()
{
    queue Test1;
    int success = 0;

    cout << "Testing isFull" << endl;

    if (Test1.isFull() == false)
    {
        cout << "Is Full passed on empty list test" << endl;
        success++;
    }
    else
    {
        cout << "IsFull failed on empty list test" << endl;
    }

    for (int i = 0; i < SIZE; i++)
    {
        Test1.enqueue(10);
    }

    if (Test1.isFull() == true)
    {
        cout << "Is Full passed on full list test" << endl;
        success++;

    }
    else
    {
        cout << "IsFull failed on full list test" << endl;
    }

    if (success == 2)
    {
        cout << "IsFull unit test passed" << endl;
    }
    else 
    {
        cout << "IsFull unit test failed" << endl;
    }

    cout << endl;
}

//Runs all of the tests in one place
void runAllTests(void)
{
    test_isEmpty();
    test_enqueue();
    test_peek();
    test_isFull();
    test_dequeue();
}