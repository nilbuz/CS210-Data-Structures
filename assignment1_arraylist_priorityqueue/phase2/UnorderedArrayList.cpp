#include "UnorderedArrayList.h"
#include <stdexcept>

UnorderedArrayList::UnorderedArrayList() {
    currentSize = 0;
    capacity = 10;
    array = new int[capacity];
}

UnorderedArrayList::UnorderedArrayList(int initialCapacity) {
    currentSize = 0;
    if (initialCapacity == 0)
        initialCapacity++;
    capacity = initialCapacity;
    array = new int[capacity];
}

bool
UnorderedArrayList::add(int data) {
    // grow array if full
    if (currentSize == capacity) {

        capacity *= 2;
        int *tempArray = new int[capacity];

        for (int i = 0; i < currentSize; i++) {
            tempArray[i] = array[i];
        }

        delete[] array;
        array = tempArray;
    }

    array[currentSize] = data;
    currentSize++;

    return true;
}

bool
UnorderedArrayList::add(int index, int data) {
    if (index < 0 || index > currentSize)
        throw std::invalid_argument("Index out of bounds.");

    // grow array if full
    if (currentSize == capacity) {

        capacity *= 2;
        int *tempArray = new int[capacity];

        for (int i = 0; i < currentSize; i++) {
            tempArray[i] = array[i];
        }

        delete[] array;
        array = tempArray;
    }

    // shift elements to the right
    for (int i = currentSize; i > index; i--) {
        array[i] = array[i - 1];
    }

    array[index] = data;
    currentSize++;
    return true;
}

void
UnorderedArrayList::clear() {
    for (int i = 0; i < currentSize; i++) {
        array[i] = 0;
    }

    currentSize = 0;
}

bool
UnorderedArrayList::contains(int data) {
    for (int i = 0; i < currentSize; i++) {
        if (array[i] == data)
            return true;
    }

    return false;
}

int
UnorderedArrayList::get(int index) {
    if (index < 0 || index >= currentSize)
        throw std::invalid_argument("Index out of bounds.");
    else
        return array[index];
}

int
UnorderedArrayList::indexOf(int data) {
    for (int i = 0; i < currentSize; i++) {
        if (array[i] == data)
            return i;
    }

    return -1;
}

bool
UnorderedArrayList::isEmpty() {
    return currentSize == 0;
}

int
UnorderedArrayList::remove(int index) {
    if (index < 0 || index >= currentSize)
        throw std::invalid_argument("Index out of bounds.");
    else {
        int tmp = array[index];

        for (int i = index; i < currentSize; i++) {   // shift elements to left

            array[i] = array[i + 1];
        }

        currentSize--;
        return tmp;
    }
}

bool
UnorderedArrayList::removeAll(int data) {

    for (int i = 0; i < currentSize; i++) {
        // if match found, shift everything after it left
        if (array[i] == data) {
            for (int j = i; j < currentSize; j++) {
                array[j] = array[j + 1];
            }
            currentSize--;
            i--;
        }
    }

    return true;
}

int
UnorderedArrayList::size() {
    return currentSize;
}

void
UnorderedArrayList::trimToSize() {
    int *tempArray = new int[currentSize];    // new array
    for (int i = 0; i < currentSize; i++) {   // copy array
        tempArray[i] = array[i];
    }
    array = tempArray;
    delete[] tempArray;
}
