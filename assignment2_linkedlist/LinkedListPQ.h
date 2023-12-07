#ifndef LINKED_LIST_PQ_H
#define LINKED_LIST_PQ_H

#include "LinkedList.h"
#include "ListIterator.h"
#include "PriorityQueue.h"
#include <stdexcept>

template <class T> class LinkedListPQ : public PriorityQueue<T> {

  private:
    LinkedList<T>* pq;

  public:
    LinkedListPQ() { pq = new LinkedList<T>; }

    //  Inserts a new object into the priority queue.  Returns true if
    //  the insertion is successful.  If the PQ is full, the insertion
    //  is aborted, and the method returns false.
    bool insert(T object) {
        // TODO
        int index = 0;   // keep track of where to put data
        ListIterator<T> p = first();
        
        // ascending order: iterate until object is <= the next node
        while (p != end() && object > *p++) {
            index++;
        }

        pq->addAt(index, object);
        return true;
    }

    //  Removes the object of highest priority that has been in the
    //  PQ the longest, and returns it.
    //  Throws invalid_argument if the PQ is empty.
    //         exception error message: "Cannot remove from empty queue"
    T remove() {
        if (isEmpty())
            throw std::invalid_argument("Cannot remove from empty queue");

        return pq->removeFirst();
    }

    //  Deletes all instances of the parameter obj from the PQ if found, and
    //  returns true.  Returns false if no match to the parameter obj is found.
    bool deleteAll(T obj) {
        if (!pq->contains(obj))
            return false;
        else
            pq->removeAll(obj);
        return true;
    }

    //  Returns the object of highest priority that has been in the
    //  PQ the longest, but does NOT remove it.
    //  Throws invalid_argument if the PQ is empty.
    //         exception error message: "Cannot peek from empty queue"
    T peek() {
        if (isEmpty())
            throw std::invalid_argument("Cannot peek from empty queue");

        return pq->peekFirst();
    }

    //  Returns true if the priority queue contains the specified element
    //  false otherwise.
    bool contains(T obj) { return pq->contains(obj); }

    //  Returns the number of objects currently in the PQ.
    int size() { return pq->size(); }

    //  Returns the PQ to an empty state.
    void clear() { pq->makeEmpty(); }

    //  Returns true if the PQ is empty, otherwise false
    bool isEmpty() { return pq->isEmpty(); }

    //  Returns true if the PQ is full, otherwise false.  List based
    //  implementations should always return false.
    bool isFull() { return false; }

    //  Returns iterator to first element in PQ list, regardless of priority
    //  order
    ListIterator<T> first() { return pq->first(); }

    //  Returns iterator to the end of the PQ list, regardless of priority order
    ListIterator<T> end() { return pq->end(); }
};
#endif
