#include "OrderedPQ.h"
#include "OrderedArrayList.h"
#include <stdexcept>

#include <iostream>

OrderedPQ::OrderedPQ() {
    pq = new OrderedArrayList(DEFAULT_MAX_CAPACITY);
}

OrderedPQ::OrderedPQ(int initialCapacity) {
    pq = new OrderedArrayList(initialCapacity);
    
}

bool
OrderedPQ::insert(int object) {
    return pq->add(object);
}

int
OrderedPQ::remove() {
    if (isEmpty())
        throw std::invalid_argument("Cannot remove from empty queue.");
    else
        return pq->remove(findMinIndex());}

int
OrderedPQ::findMinIndex() {
    return 0;
}

bool
OrderedPQ::deleteAll(int obj) {
    return pq->removeAll(obj);
}

int
OrderedPQ::peek() {
    if (isEmpty())
        throw std::invalid_argument("Cannot peek from empty queue.");
    else
        return pq->get(findMinIndex());}

bool
OrderedPQ::contains(int obj) {
    return pq->contains(obj);
}

int
OrderedPQ::size() {
    return pq->size();
}

void
OrderedPQ::clear() {
    pq->clear();
}

bool
OrderedPQ::isEmpty() {
    return pq->isEmpty();
}

bool
OrderedPQ::isFull() {
    return false;
}

void
OrderedPQ::print() {
    std::cout << "\t";
    for (int i =0; i < pq->size(); i++) {
        std::cout << pq->get(i) << " ";
    }
    std::cout << std::endl;
}