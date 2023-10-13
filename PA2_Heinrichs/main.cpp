/*
Gabe Heinrichs
PA2

Run PA2_exe inside of the BuildFolder to run the code!

*/

#pragma once
#include "AVLTree.hpp"
#include "Tests.hpp"

using std::cout;
using std::endl;


int main(void)  
{
    // int insert_values = 1;
    // tree.insert(insert_values);
    // insert_values = 2;
    // tree.insert(insert_values);
    // insert_values = 3;
    // tree.insert(insert_values);
    // insert_values = 4;
    // tree.insert(insert_values);
    // insert_values = 5;
    // tree.insert(insert_values);
    // insert_values = 6;
    // tree.insert(insert_values);
    // insert_values = 8;
    // tree.insert(insert_values);
    // insert_values = 7;
    // tree.insert(insert_values);
    // insert_values = -1;
    // tree.insert(insert_values);
    // //tree.print_tree_in_order();
    // tree.print_2D_tree();
    // tree.print_2D_tree();
    test_ascending_order();
    test_descending_order();
    test_random_order();
    return 0;
}