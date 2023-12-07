#include "OrderedArrayList.h"
#include <iostream>
#include <ostream>
#include <stdexcept>

OrderedArrayList::OrderedArrayList() {
    currentSize = 0;
    capacity = 10;
    array = new int[capacity];

    for (int i = 0; i < capacity;) {
    }
}

OrderedArrayList::OrderedArrayList(int initialCapacity) {
    currentSize = 0;
    if (initialCapacity == 0)
        initialCapacity++;
    capacity = initialCapacity;
    array = new int[capacity];
}

bool
OrderedArrayList::add(int data) {
    // grow array if full
    growArray();

    // binary search to find right insertion point

    int first = 0;
    int last = currentSize - 1;
    int mid = (first + last) / 2;

    while (first <= last) {
        if (data == array[mid]) {   // if found a duplicate of data, just break
                                    // and insert it right there
            break;
        } else if (data < array[mid]) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
        mid = (first + last) / 2;
    }

    // shift elements to the right
    for (int i = currentSize; i > first; i--) {
        array[i] = array[i - 1];
    }

    array[first] = data;
    currentSize++;
    return true;
}

bool
OrderedArrayList::add(int index, int data) {
    if (index < 0 || index > currentSize)
        throw std::invalid_argument("Index out of bounds.");

    // check if data abides by order
    if ((index > 0 && data < array[index - 1]) ||
        (index < currentSize && data > array[index]))
        throw std::invalid_argument(
            "Data at requested index would violate sorting order.");

    // grow array if full
    growArray();

    // shift elements to the right
    for (int i = currentSize; i > index; i--) {
        array[i] = array[i - 1];
    }

    array[index] = data;
    currentSize++;
    return true;
}

void
OrderedArrayList::clear() {
    for (int i = 0; i < currentSize; i++) {
        array[i] = 0;
    }

    currentSize = 0;
}

bool
OrderedArrayList::contains(int data) {

    // true if binary search found it
    return (binarySearch(data) == -1 ? false : true);
}

int
OrderedArrayList::get(int index) {
    if (index < 0 || index >= currentSize)
        throw std::invalid_argument("Index out of bounds.");
    else
        return array[index];
}

int
OrderedArrayList::indexOf(int data) {
    // do a binary search repeatedly to find first occurance of data
    return binarySearchFindFirstOccurance(data);
}

bool
OrderedArrayList::isEmpty() {
    return currentSize == 0;
}

int
OrderedArrayList::remove(int index) {
    if (index < 0 || index >= currentSize)
        throw std::invalid_argument("Index out of bounds.");

    int tmpResult = array[index];

    for (int i = index; i < currentSize; i++) {   // shift elements to left
        array[i] = array[i + 1];
    }

    currentSize--;
    return tmpResult;
}

bool
OrderedArrayList::removeAll(int data) {

    // binary search for element, then linearly remove any existing duplicates
    // after it

    int index = binarySearchFindFirstOccurance(data);
    int shiftSize = 0;

    for (int i = index; i < currentSize; i++) {
        // if match found, shift everything after it left
        if (array[i] == data) {
            shiftSize++;
        } else {
            break;
        }
    }

    // remove the elements and possible duplicates by shifting elements to left
    for (int i = index; i < index + shiftSize; i++) {
        array[i] = array[i + shiftSize];
        currentSize--;
    }

    return true;
}

int
OrderedArrayList::size() {
    return currentSize;
}

void
OrderedArrayList::trimToSize() {
    int *tempArray = new int[currentSize];    // new array
    for (int i = 0; i < currentSize; i++) {   // copy array
        tempArray[i] = array[i];
    }
    delete[] array;
    array = tempArray;
}

int
OrderedArrayList::binarySearch(int data) {
    // binary search
    int first = 0;
    int last = currentSize - 1;
    int mid = (first + last) / 2;

    while (first <= last) {
        if (data == array[mid]) {
            return mid;
        } else if (data < array[mid]) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
        mid = (first + last) / 2;
    }
    return -1;
}

// do a binary search repeatedly to find first occurance of data
int
OrderedArrayList::binarySearchFindFirstOccurance(int data) {

    int first = 0;
    int last = currentSize - 1;
    int mid = (first + last) / 2;

    int result = -1;

    while (first <= last) {
        if (data == array[mid]) {
            result = mid;
            last = mid - 1;   // if found matching element, move last pointer to
                              // the left, to try to find a element matching
                              // data closer to start
        } else if (data < array[mid]) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
        mid = (first + last) / 2;
    }

    return result;
}

void
OrderedArrayList::growArray() {
    if (currentSize == capacity) {

        capacity *= 2;
        int *tempArray = new int[capacity];

        for (int i = 0; i < currentSize; i++) {
            tempArray[i] = array[i];
        }

        delete[] array;
        array = tempArray;
    }
}

// remove later
// void
// OrderedArrayList::print() {
//     for (int i = 0; i < currentSize; i++) {
//         std::cout << array[i] << " ";
//     }
//     std::cout << std::endl << std::endl;
// }