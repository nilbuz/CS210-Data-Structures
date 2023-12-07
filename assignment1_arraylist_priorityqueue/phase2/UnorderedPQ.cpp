#include "UnorderedPQ.h"
#include "UnorderedArrayList.h"
#include <iostream>

#include <stdexcept>

UnorderedPQ::UnorderedPQ() {
    pq = new UnorderedArrayList(DEFAULT_MAX_CAPACITY);
}

UnorderedPQ::UnorderedPQ(int initialCapacity) {
    pq = new UnorderedArrayList(initialCapacity);
}

bool
UnorderedPQ::insert(int object) {
    return pq->add(object);
}

int
UnorderedPQ::remove() {
    if (isEmpty())
        throw std::invalid_argument("Cannot remove from empty queue.");
    else
        return pq->remove(findMinIndex());
}

int
UnorderedPQ::findMinIndex() {
    // linear search to find highest priority
    int min = 0;
    for (int i = 0; i < size(); i++) {
        if (pq->get(i) < pq->get(min))
            min = i;
    }
    return min;
}

bool
UnorderedPQ::deleteAll(int obj) {
    return pq->removeAll(obj);
}

int
UnorderedPQ::peek() {
    if (isEmpty())
        throw std::invalid_argument("Cannot peek from empty queue.");
    else
        return pq->get(findMinIndex());
}

bool
UnorderedPQ::contains(int obj) {
    return pq->contains(obj);
}

int
UnorderedPQ::size() {
    return pq->size();
}

void
UnorderedPQ::clear() {
    pq->clear();
}

bool
UnorderedPQ::isEmpty() {
    return pq->isEmpty();
}

bool
UnorderedPQ::isFull() {
    return false;
}

void
UnorderedPQ::print() {
    std::cout << "\t";
    for (int i = 0; i < pq->size(); i++) {
        std::cout << pq->get(i) << " ";
    }
    std::cout << std::endl;
}
