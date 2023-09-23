#pragma once
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

//This singular node allows us to store both pieces of data associated with a command\
allowing us to have a more condnsed program
typedef struct node
{
    string command;
    string commandDescription;
    struct node *pNext;

    void operator=(const struct node& rhs)
    {
        command = rhs.command;
        commandDescription = rhs.commandDescription;
        pNext = rhs.pNext;
    }

    void operator==(const node* rhs)
    {
        command = rhs->command;
        commandDescription = rhs->commandDescription;
        pNext = nullptr;
    }
    
} Node;


typedef struct profile_Node
{
    string profile_name;
    int profile_score;
    struct profile_Node *pNext;

}Profile_Node;

//partial code snippet from https://stackoverflow.com/questions/5740310/no-operator-found-while-comparing-structs-in-c 
bool operator==(const Node& lhs, const Node& rhs)
{
    bool result = false;

    if (lhs.command == rhs.command)
    {
        result = true;
    } 
    return result; /* your comparison code goes here */
}



template <typename t> class List
{   
    public:
    //Initial Constructor
    List(void)
    {
        pHead = nullptr;
        size = 0;
    }

    //This calls a recursive function "destructor", which will call itself until the entire tree is deallocated
    ~List(void)
    {
        destructor(pHead);
    }

    //I only have an insert at end function because I wanted to add things sequentially as they came into the solution
    void insert_command_at_end(t &new_node) 
    {
        t *pCur = pHead;
        t *p_insert_node = new t;

        
        p_insert_node->command = new_node.command;
        p_insert_node->commandDescription = new_node.commandDescription;
        p_insert_node->pNext = nullptr;

        if (is_empty())
        {
            pHead = p_insert_node;
        }
        else  
        {
            while (pCur->pNext != nullptr)
            {

                pCur = pCur->pNext;
            }

            //insertNode
            pCur->pNext = p_insert_node;
        }

        this->size += 1;
    }

    //Checks whether or not the list is empty. Used in insert_at_end
    bool is_empty(void)
    {
        if (pHead == nullptr)
        {
            return true;
        }
        return false;
    }

    //Prints the list from the first node to the last one
    void print_command_list(void)
    {
        t * pCur = pHead;

        while (pCur != nullptr)
        {
            cout << pCur->command << ": " << pCur->commandDescription << endl;
            pCur = pCur->pNext;
        }
    }

    void print_profile_list(void)
    {
        t * pCur = pHead;

        while (pCur != nullptr)
        {
            cout << pCur->profile_name << "," << pCur->profile_score << endl;
            pCur = pCur->pNext;
        }
    }

    t go_to_command_node(int destination)    
    {
        t *pCur = pHead;
        t return_Node;
        
        if (destination >= 0 && destination < size)
        {
            for (int i = 0; i < destination; i++)
            {
                pCur = pCur->pNext;
            }

            return_Node.command = pCur->command;
            return_Node.commandDescription = pCur->commandDescription;
        }
        else
        {
            throw std::out_of_range("Out of scope");
        }

        return return_Node; // This will only be reached if the condition is met
    }

    t go_to_profile_node(int destination)    
    {
        t *pCur = pHead;
        t return_Node;
        
        if (destination <= size || destination > 0)
        {
            for (int i = 0; i < destination; i++)
            {
                pCur = pCur->pNext;
            }

            return_Node.profile_name = pCur->profile_name;
            return_Node.profile_score = pCur->profile_score;
        }
        else
        {
            cout << "out of scope";
        }
        return return_Node;
    }

    int get_size(void)
    {  
        return size;
    }

    void insert_profile_at_end(t &new_node)
    {
        t *pCur = pHead;
        t *p_insert_node = new t;

        p_insert_node->profile_name = new_node.profile_name;
        p_insert_node->profile_score = new_node.profile_score;
        p_insert_node->pNext = nullptr;
        if (is_empty())
        {
            pHead = p_insert_node;
        }
        else  
        {
            while (pCur->pNext != nullptr)
            {

                pCur = pCur->pNext;
            }

            //insertNode
            pCur->pNext = p_insert_node;
        }

        this->size += 1;
    }

    void delete_node_at_end(void)   
    {
        if (size != 0)
        {
            t* pCur = pHead;
            t* pDelete = nullptr; 

            for (int i = 0; i < size - 2; i++) 
            {
                pCur = pCur->pNext;
            }

            pDelete = pCur->pNext;
            pCur->pNext = nullptr;
            
            // Delete the node and set it to nullptr
            delete pDelete;
            pDelete = nullptr;

            size--; 
        }
    }

    private:
    t *pHead;
    int size;

    //recursivly de-allocates memory in a list
    void destructor(t *pCur)
    {
        if (!this->is_empty())
        {
            if (pCur->pNext != nullptr)
            {
                destructor(pCur->pNext);
            }
            //cout << "Deleting " << pCur->command << endl;
            delete pCur; 
        }
    }
};

 