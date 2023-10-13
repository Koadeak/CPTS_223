#pragma once
#include "AVLNode.hpp"
#include <iostream>

using std::cout;
using std::endl;
#define COUNT 10

template <typename T> class AVLTree
{
    public:
    AVLTree(void)
    {
        p_root = nullptr;
    }

    //if the tree isn't empty it will call the constructor
    ~AVLTree()
    {
        if (p_root)
        {
            destructor(p_root);
        }
    }

    //returns the height of the tree
    int get_height(void)
    {
        if (p_root)
        {
            return p_root->get_height();
        }
        else
        {
            return -1;
        }

    }

    //returns the balance of the tree. if the tree is left heavy, the return value will be positive, and if it will be right heavy, it will return a negetive value
    int get_balance_factor(AVLNode<T> * p_cur)
    {
        return get_node_height(p_cur->p_left) - get_node_height(p_cur->p_right);
    }

    //is the wrapper version of the insert function, doesn't require any pointers
    void insert(T &new_data)
    {
        
        if (p_root == nullptr)
        {
            p_root = new AVLNode<T>(new_data, 0);
        }
        else
        {
            insert(p_root, new_data, 1);
        }
    }

    //prints the elements in the tree in order
    void print_tree_in_order(void)
    {
        if (p_root)
        {
            print_tree_in_order(p_root);
        }
        cout << endl;
    }

    //checks if an element is included into a list
    bool contains(T search_value)
    {
        return contains_helper(search_value, p_root);
    }

    // Wrapper over print2DUtil()
    //edited version of function from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/ to visualize tree
    void print_2D_tree(void)
    {
        // Pass initial space count as 0
        print2DUtil(p_root, 0);
    }

    // Wrapper over print2DUtil()
    //edited version of function from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/ to visualize tree
    void print_2D_tree(AVLNode<T> *node)
    {
        // Pass initial space count as 0
        print2DUtil(node, 0);
    }


    //returns the root
    AVLNode<T> * get_root()
    {
        return p_root;
    }

    //checks if the tree is valid
    bool validate(void)
    {
        if (get_balance_factor(p_root) <= 1 && get_balance_factor(p_root) >= -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    private:
    AVLNode<T> *p_root;

    //Does a standard insert into a BST, and then immediatly rotates the tree to become balanced. This means that the tree will always be balanced
    void insert(AVLNode<T> *p_cur, T &new_data, int height)
    {
        //check if node should be inserted left or right
        if (new_data < p_cur->m_Data)
        {
            //insert left
            if (p_cur->p_left == nullptr)
            {
                p_cur->p_left = new AVLNode<T>(new_data, height);
            }
            else
            {
                insert(p_cur->p_left, new_data, height + 1);
            }
        }
        else
        {
            if (p_cur->p_right == nullptr)
            {
                p_cur->p_right = new AVLNode<T>(new_data, height);
            }
            else
            {
                insert(p_cur->p_right, new_data, height + 1);
            }
        }

        handle_rotation();
    }

    //recursivly destroys the tree
    void destructor(AVLNode<T> *p_cur)
    {
        if (p_cur == nullptr) 
        {
            return;
        }

        //traverse left
        destructor(p_cur->p_left);
        //traverse right
        destructor(p_cur->p_right);
        //delete root
        delete p_cur;
    }
    
    //prints the tree in ascending order. This one does require a pointer
    void print_tree_in_order(AVLNode<T> *p_cur)
    {
        if (p_cur == nullptr)
         {
        return; // Return if the node is nullptr (empty)
        }   

        if (p_cur->p_left != nullptr)
        {
            print_tree_in_order(p_cur->p_left);
        }
        std::cout << p_cur->m_Data << " ";
        if (p_cur->p_right != nullptr)
        {
            print_tree_in_order(p_cur->p_right);
        }
    }

    //returns the height of a node
    int get_node_height(AVLNode<T> *targetNode)
    {
        return targetNode->get_height();
    }   

    // Function to print binary tree in 2D
    // It does reverse inorder traversal
    //edited version of function from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/ to visualize tree
    void print2DUtil(AVLNode<T> * root, int space)
    {
        // Base case
        if (root == NULL)
            return;
    
        // Increase distance between levels
        space += COUNT;
    
        // Process right child first
        print2DUtil(root->p_right, space);
    
        // Print current node after space
        // count
        cout << endl;
        for (int i = COUNT; i < space; i++)
            cout << " ";
        cout << root->m_Data << "\n";
    
        // Process left child
        print2DUtil(root->p_left, space);
    }

    //When rotating right or left, there are usually only two nodes that really need to be rotated, the rest of the tree just follows along
    //X and Y are just
    void rotate_left(AVLNode<T> **rotate_node)
    {
        AVLNode<T> *x = *rotate_node;
        AVLNode<T> *y = x->p_right;
        AVLNode<T> *temp = y->p_left;

        y->p_left = x;
        y->height++;
        x->p_right = temp;
        x->height--;


        *rotate_node = y;
    }

    //rotates the rotate node to the right, references x and y because the video that showed me the theory of a BST used x and y
    void rotate_right(AVLNode<T> **rotate_node)
    {
        AVLNode<T> *x = *rotate_node;
        AVLNode<T> *y = x->p_left;
        AVLNode<T> *temp = y->p_right;

        y->p_right = x;
        y->height++;
        x->p_left = temp; 
        x->height--;


        *rotate_node = y;
    }

    //really isn't necessary in my implementation, but thought it would be based on how the video was taught to me
    void rotate_right_left(AVLNode<T> **rotate_node)
    {
        AVLNode<T> *z = *rotate_node;
        AVLNode<T> *y = z->p_right;
        AVLNode<T> *x = y->p_left;

        // Perform a right rotation on 'y'.
        rotate_right(&(z->p_right));

        // Now, 'z' is a left child of 'y'. Perform a left rotation on 'z'.
        rotate_left(rotate_node);
    }

    //really isn't necessary in my implementation, but thought it would be based on how the video was taught to me
    void rotate_left_right(AVLNode<T> **rotate_node)
    {
        AVLNode<T> *z = *rotate_node;
        AVLNode<T> *y = z->p_left;
        AVLNode<T> *x = y->p_right;

        // Perform a left rotation on 'y'.
        rotate_left(&(z->p_left));

        // Now, 'z' is a left child of 'y'. Perform a right rotation on 'z'.
        rotate_right(rotate_node);
    }

    //wrapper so we don't have to worry about pointers when rotating a tree
    void handle_rotation(void)
    {
        while (get_balance_factor(p_root) > 1 || get_balance_factor(p_root) < -1)
        {
            balance(&p_root);
        }
    }

    //balances the tree using only the rotate_left and rotate_right functions to rotate. recursive
    void balance(AVLNode<T> **p_cur)
    {
        if (*p_cur == nullptr)
         {
            return;
        }
        // Go to left most node
        balance(&((*p_cur)->p_left)); //because we need to have a double star to edit only the target node (which could be the root)
        balance(&((*p_cur)->p_right));

        if (get_balance_factor(*p_cur) > 1) 
        {
            rotate_right(p_cur);
        } else if (get_balance_factor(*p_cur) < -1)
        {
            rotate_left(p_cur);
        }
    }   

    //recursive finder to help see if an element is in a list
    bool contains_helper(T &search_value, AVLNode<T>* p_cur)
    {
        if (p_cur == nullptr)
        {
            return false;
        }
        if (p_cur->m_Data == search_value)
        {
            return true;
        }
        else if (search_value < p_cur->m_Data)
        {
            //go left
            return contains_helper(search_value, p_cur->p_left);
        }
        else if (search_value > p_cur->m_Data)
        {
            //go right
            return contains_helper(search_value, p_cur->p_right);
        }
    }
    
};


 
