#include <iostream>


template <typename T> class AVLNode
{
    public:
    T m_Data;
    int height;
    AVLNode<T> *p_right, *p_left;

    AVLNode(void)
    {
        p_left = nullptr;
        p_right = nullptr;
        height = 0;
    }

    AVLNode(T &new_data, int height)
    {
        p_left = nullptr;
        p_right = nullptr;
        height = 0;
        m_Data = new_data;
    }

    int get_height(void)   
    {
        return get_height_helper(this);
        
    }

    ~AVLNode()
    {

    }

    private:

    //this is a recursive function that will find the height of the current node
    int get_height_helper(AVLNode<T> *pCur)
    {
        if (pCur == nullptr)
        {
        return -1;
        }

        int left_max = get_height_helper(pCur->p_left);
        int right_max = get_height_helper(pCur->p_right);
        
        if (left_max >= right_max)
        {
            return left_max + 1;
        }
        else
        {
            return right_max + 1;
        }
    }
};