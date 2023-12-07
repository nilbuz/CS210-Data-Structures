// HashTable.cpp
// Author: Bryan Zublin
// ID: 828354677

#include "HashTable.h"
#include "LinkedList.h"
#include <cstddef>
//#include <iostream>

namespace HashTableNS {

// Initialize empty hash table
HashTable::HashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashArray[i] = NULL;
    }
}

// Destructor destroys hash table
HashTable::~HashTable() {
    for (Node<string>* bucket : hashArray) {
        Node<string>* temp = bucket;
        while (bucket != NULL) {
            temp = bucket;
            bucket = bucket->getLink();
            delete temp;
        }
    }
}

// Returns true if target is in the hash table,
// false otherwise
bool HashTable::containsString(string target) const {
    int bucketIndex = computeHash(target) % SIZE;   // index = hash value % size

    if (LinkedListNS::search(hashArray[bucketIndex], target) == NULL) {
        return false;
    } else {
        return true;
    }
}

// Adds a new string to the hash table
void HashTable::put(string s) {

    int bucketIndex = computeHash(s) % SIZE;   // index = hash value % size
    LinkedListNS::headInsert(hashArray[bucketIndex], s);   // insert into chain

    //std::cout << "put " << s << ": " << bucketIndex << std::endl;
}

// multiplicative string hash function
// initial value 17
// for each char, multiply hash value by 3
// add ascii value
int HashTable::computeHash(string s) {

    int hash = 17;
    for (int i = 0; i < s.length(); i++) {
        hash *= 3;
        hash += (char) s.at(i);
    }

    return hash;
}

}   // namespace HashTableNS