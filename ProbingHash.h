#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>
#include <stdlib.h>


#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
struct Node 
{
    K first;
    V second;
    EntryState current_state;
};



template<typename K, typename V>
class ProbingHash : public Hash<K,V> { // derived from Hash
private:
    std::vector<Node<K,V> > Hashtable; //using a node because we will need to store 3 values
    

public:
    /*
    Name: ProbingHash
    Description: This constructor initializes a Probing Hash Table with a specified or default bucket count and maximum string size. It prepares the table for storing elements and sets the current prime for probing operations.

    Parameters:
    - int n (optional, default = 11): The number of buckets in the hash table.
    - int max_string_size (optional, default = 50): The maximum string size for probing operations.
    Returns: N/A 
    */
    ProbingHash(int n = 11, int max_string_size = 50) //guessing that n is the tableSize/ bucket count
    {
        current_prime = findNextPrime(max_string_size);
        if (isPrime(n) == false)
        {
            bucket_count = findNextPrime(n);
        }
        else
        {
            bucket_count = n;
        }
        //initialize vector for storage
        populate_empty_hashtable();
    }

    ~ProbingHash() 
    {
        this->clear();
    }

    /*
    Name: size
    Description: This function returns the number of elements currently stored in the Chaining Hash Table.

    Parameters: N/A
    Returns: int - The number of elements in the hash table.
    */
    int size() // Quantity of elements with a specific state in the hash
    {
        return number_of_valid_elements;
    }

    /*
    Name: operator[]
    Description: This operator function allows you to access the value associated with a given key in the Probing Hash Table. If the key is not found, it returns a default value (NULL) and displays a message.

    Parameters: const K& key - The key for which you want to access the associated value.
    Returns: V - The value associated with the given key or a default value if the key is not found.
    */
    V operator[](const K& key) //Returns the value with key k. in any other table.
    {
        int i = 0;
        int key_hash_val = hash(key);
        V return_val;
        while (Hashtable[key_hash_val+i].first != key && Hashtable[key_hash_val+i].second != NULL)
        {
            i++;
            if (i == bucket_count)
            {
                i = 0;
            }
        }

        if (Hashtable[key_hash_val+i].second == NULL)
        {
            //std::cout << "Either a value with this key does not exist, or it was deleted" << std::endl;
            return_val = -1;
        }
        else
        {
            return_val = Hashtable[key_hash_val + i].second;
        }

        return return_val;
    }

    /*
    Name: insert
    Description: This function inserts a key-value pair into the Probing Hash Table. It utilizes probing to find an available slot and returns true if the insertion is successful.

    Parameters: const std::pair<K, V>& pair - The key-value pair to be inserted.

    Returns: bool - True if the insertion was successful, otherwise false.
    */
    bool insert(const std::pair<K, V>& pair) //Adds pair to hash, true if successful
    {
        int key_hash_val = hash(pair.first);
        Node<K,V> insert_node;
        insert_node.first = pair.first;
        insert_node.second = pair.second;
        insert_node.current_state = VALID;

       
        //insert value at vector point
        int i = 0;
        while (Hashtable[key_hash_val + i].current_state != EMPTY)
        {
            //go back to the begining
            if (i >= bucket_count)
            {
                i = -key_hash_val;
            }

            //std::cout << "We are trying to insert" << std::endl;
            i++;
        }

        //std::cout << "Inserted element " << pair.first << " with value " << pair.second << " at position " << key_hash_val + i << std::endl;
        if ((Hashtable[key_hash_val + i].current_state == DELETED))
        {
            insert_node.current_state = DELETED;
        }
        Hashtable[key_hash_val + i].first = insert_node.first;
        Hashtable[key_hash_val + i].second = insert_node.second;
        Hashtable[key_hash_val + i].current_state = insert_node.current_state;
        number_of_valid_elements += 1;

         //check if we should rehash, only when load factor is greater than .75
        if (load_factor() > .75)
        {
            //std::cout << "we are in here" << std::endl;
            rehash();
        }

        return true;
    }

    //for testing purposes
    int test_hash(K &key)
    {
        return hash(key);
    }

    /*
    Name: erase
    Description: This function removes any entries with the specified key from the Probing Hash Table, marking them as deleted. It reduces the count of valid elements.

    Parameters: const K& key - The key to be removed.

    Returns: N/A
    */
    void erase(const K& key) //Removes all any (if any) entries with key k
    {
        int key_hash_val = hash(key);
        int i = 0;

        //delete contents of node
        Hashtable[key_hash_val].first = key_hash_val;
        Hashtable[key_hash_val].second = NULL;
        Hashtable[key_hash_val].current_state = DELETED;
        number_of_valid_elements -= 1;
    }

    /*
    Name: clear
    Description: This function empties the Probing Hash Table, removing all elements and resetting the table to its initial state.

    Parameters: N/A

    Returns: N/A
    */
    void clear() //Empties the hash
    {
        Hashtable.clear();
    }

    /*
    Name: load_factor
    Description: This function gets the load factor of the table

    Parameters: N/A
    Returns: float load factor - number of elements / bucket count
    */
    float load_factor() //Returns the load factor of the hash
    {
        return (float) number_of_valid_elements / (float) /*Hashtable.capacity()*/ bucket_count;
    }

    /*
    Name: get_bucket_count
    Description: This function clears the hashtable

    Parameters: N/A
    Returns: int bucket_count - how many buckets in the table
    */
    int get_bucket_count() //Returns the number of buckets allocated (size of the hash vector)
    //Note that bucket count represents the tablesize... 
    {
        return bucket_count;
    }

private:
    int bucket_count;
    int current_prime;
    int number_of_valid_elements;

    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    /*
    Name: populate_empty_hashtable
    Description: This will resize the hashtable so that we can double the size of the hashtable

    Parameters: N/A
    Returns: N/A
    */
    void populate_empty_hashtable(void)
    {
        Hashtable.resize(bucket_count);
    }

    /*
    Name: rehash
    Description: This function performs a rehash operation, doubling the bucket count and redistributing elements to maintain efficient data storage in the Probing Hash Table.

    Parameters: N/A

    Returns: N/A
    */
    void rehash() 
    {
        std::pair<K, V> temp;
        std::vector<Node<K, V> > old_table = Hashtable;  // Create a copy of the old table
        clear();
        bucket_count = findNextPrime(bucket_count * 2);
        populate_empty_hashtable();
        number_of_valid_elements = 0;

        for (Node<K, V> &node : old_table) { //new method i've learned to traverse a hashtable, kinda cool
            if (node.current_state == VALID) {
                temp.first = node.first;
                temp.second = node.second;
                insert(temp);  // Insert elements into the new table
            }
        }
    }   
    
    /*
    Name: hash
    Description: Hashes the key. The method of doing so as simple as it gets. 

    Parameters: N/A
    Returns: int hash_value 
    */
    int hash(const K& key) //using Horner's method for hashing 
    {
        return key % bucket_count;       
    }
    
};

#endif //__PROBING_HASH_H