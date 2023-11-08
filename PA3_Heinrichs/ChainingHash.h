/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

// Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash


template<typename K, typename V>
class ChainingHash : public Hash<K,V> {
private:
    std::vector<std::list<std::pair<K,V> > > Hashtable; 
    int bucket_count;
    int number_of_elements;

public:

    /*
    Name: ChainingHash
    Description: This constructor initializes a Chaining Hash Table with a specified or default bucket count. It uses linked lists in each bucket for collision resolution.

    Parameters: int n (optional, default = 11) - The number of buckets in the hash table.
    Returns: N/A (Constructor)
    */
    ChainingHash(int n = 11) 
    {
        std::pair<K, V> temp;
        std::list<std::pair<K, V> > temp_list;
        
        if (isPrime(n) == false)
        {
            bucket_count = findNextPrime(n);
        }
        else
        {
            bucket_count = n;
        }
        
        number_of_elements = 0;


        for (int i = 0; i < bucket_count; i++)
        {
            temp.first = K();
            temp.second = V(); // Use the default constructor to initialize temp.second
            temp_list.push_back(temp);
            Hashtable.push_back(temp_list);
            Hashtable[i].clear();

        }
    }

    ~ChainingHash()
    {
        this->clear();
    }
    /*
    Name: size
    Description: This function returns the number of elements currently stored in the Chaining Hash Table.

    Parameters: N/A
    Returns: int - The number of elements in the hash table.
    */
    int size() 
    {
        return number_of_elements;
    }

    /*
    Name: operator[]
    Description: This operator function allows you to access the value associated with a given key in the Chaining Hash Table. If the key is not found, it returns a default value (NULL) and displays a message.

    Parameters: const K& key - The key for which you want to access the associated value.
    Returns: V - The value associated with the given key or a default value if the key is not found.
    */
    V operator[](const K& key) 
    {
        V return_value = NULL;
        std::list<std::pair<K,V> > &current_bucket = Hashtable[hash(key)];

        for (auto it = current_bucket.begin(); it != current_bucket.end(); it++)
        {
            if (it->first == key)
            {
                return_value = it->first;
                break;
            }
        }
        
        if (return_value == NULL)
        {
            std::cout << "This element is not in the Hashtable or has been deleted" << std::endl;
        }
        return return_value;
    }

    /*
    Name: insert
    Description: This function inserts a key-value pair into the Chaining Hash Table. If the load factor exceeds a threshold, it triggers a rehash operation to maintain efficient data storage.

    Parameters: const std::pair<K, V>& pair - The key-value pair to be inserted.
    Returns: bool - True if the insertion was successful, otherwise false.
    */
    bool insert(const std::pair<K, V>& pair) 
    {
        //std::cout << "Inserting " << pair.first << " at " << hash(pair.first) << std::endl;
        int key_hash_val = hash(pair.first);

        std::list<std::pair<K,V> > &current_bucket = Hashtable[key_hash_val];

        if (current_bucket.empty())
        {
            current_bucket.push_front(pair);
        }
        else
        {
            //cout << "Inserting element in non empty list"   << endl;
            current_bucket.push_back(pair);
        }

        number_of_elements++;
        


        if (load_factor() >= 0.75)
        {
            rehash();
        }

        return true;
    }
    /*
    Name: erase
    Description: This function removes an element with a specified key from the Chaining Hash Table, if it exists.

    Parameters: const K& key - The key of the element to be removed.
    Returns: N/A
    */
    void erase(const K& key) 
    {
        std::list<std::pair<K,V> > &current_bucket = Hashtable[hash(key)];
        current_bucket.remove(std::make_pair(key, V()));
        number_of_elements--;
    }

    /*
    Name: clear
    Description: This function clears the hashtable

    Parameters: N/A
    Returns: N/A
    */
    void clear() 
    {
        Hashtable.clear();
    }  

    /*
    Name: get_bucket_count
    Description: This function clears the hashtable

    Parameters: N/A
    Returns: int bucket_count - how many buckets in the table
    */
    int get_bucket_count()
    {
        return bucket_count;
    }

    /*
    Name: load_factor
    Description: This function gets the load factor of the table

    Parameters: N/A
    Returns: float load factor - number of elements / bucket count
    */
    float load_factor() 
    {
        return (float) number_of_elements / (float) get_bucket_count();
    }

private:
    
    //depreciated function
    void populate_empty_hashtable(void)
    {
        std::pair<K, V> temp;
        std::list<std::pair<K, V> > temp_list;

        for (int i = 0; i < bucket_count; i++)
        {
            temp.first = K();
            temp.second = V(); // Use the default constructor to initialize temp.second
            temp_list.push_back(temp);
            Hashtable.push_back(temp_list);
        }
    }

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
    Name: hash
    Description: Hashes the key. The method of doing so as simple as it gets. 

    Parameters: N/A
    Returns: int hash_value 
    */
    int hash(const K& key)
    {
        return key % bucket_count;
    }

    /*
    Name: rehash
    Description: This function performs a rehash operation by doubling the bucket count and redistributing elements to maintain a low load factor and efficient data storage in the Chaining Hash Table.

    Parameters: N/A
    Returns: N/A
    */
    void rehash(void)
    {
        // Store the current bucket count and elements
        size_t old_bucket_count = bucket_count;
        std::vector<std::list<std::pair<K, V> > > oldHashtable = Hashtable;

        // Double the bucket count and initialize the new hash table
        bucket_count = findNextPrime(bucket_count * 2);
        Hashtable.clear();
        Hashtable.resize(bucket_count);
        
        // Reset the number of elements
        number_of_elements = 0;

        // Reinsert the elements from the old hash table
        for (size_t i = 0; i < old_bucket_count; ++i)
        {
            for (auto& pair : oldHashtable[i])
            {
                insert(pair);
                
            }
        }
    }

};

#endif //__CHAINING_HASH_H
