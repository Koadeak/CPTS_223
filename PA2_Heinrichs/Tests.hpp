#include "AVLTree.hpp"
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>


void test_ascending_order(void)
{
    AVLTree<int> tree;
    cout << "Testing Ascending order insert into AVL tree\n\n";

    //creating a data structure seems redundant if we are going in ascending order
    for (int i = 1; i < 100; i+=2)
    {
        tree.insert(i);
    }

    //validate tree

    for (int i = 0; i < 100; i++)
    {
        cout << "does the tree containt " << i  << "? " << tree.contains(i) << endl;
    }

    if (tree.validate() && tree.contains(99))
    {
        cout << "Test inserting nodes ascending order has passed!" << endl;
    }
    else 
    {
        cout << "Test inserting nodes in ascending order failed" << endl;
    }
}

void test_descending_order(void)
{
    AVLTree<int> tree;

    //creating a data structure seems redundant if we are going in ascending order
    for (int i = 99; i > 0; i-=2)
    {
        tree.insert(i);
    }

    //validate tree
    for (int i = 0; i < 100; i++)
    {
        cout << "does the tree containt " << i  << "? " << tree.contains(i) << endl;
    }

    if (tree.validate() && tree.contains(99))
    {
        cout << "Test inserting nodes descending order has passed!" << endl;
    }
    else 
    {
        cout << "Test inserting nodes in descending order failed" << endl;
    }
}

void test_random_order(void)
{
    std::vector<int> list;
    AVLTree<int> tree;

    for (int i = 1; i < 100; i += 2)
    {
        list.push_back(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(list.begin(), list.end(), g);


    for (auto i = list.begin(); i != list.end(); ++i)
    {
        tree.insert(*i);
    }
    for (int i = 0; i < 100; i++)
    {
        cout << "does the tree containt " << i  << "? " << tree.contains(i) << endl;
    }

    if (tree.validate() && tree.contains(99))
    {
        std::cout << "Test inserting nodes randomly has passed!" << std::endl;
    }
    else
    {
        std::cout << "Test inserting nodes randomly failed" << std::endl;
    }
}