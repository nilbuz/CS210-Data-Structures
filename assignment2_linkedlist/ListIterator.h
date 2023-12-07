#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "Node.h"

template <class T> class ListIterator {
  private:
    Node<T>* itptr;   // Pointer to traverse the linked list
  public:
    ListIterator() { itptr = nullptr; }
    ListIterator(const ListIterator<T>& q) { itptr = q.itptr; }
    ListIterator(Node<T>* q) { itptr = q; }

    ListIterator& operator++() {   // prefix, ++p
        itptr = itptr->next;
        return *this;
    }

    ListIterator operator++(int) {   // postfix, p++ch
        ListIterator<T> tmp = *this;   // make a copy of current state
        ++*this;      // call prefix to update the state, ++(*this)
        return tmp;   // return the copy of the now former state
    }

    bool operator==(ListIterator<T> q) { return itptr == q.itptr; }
    bool operator!=(ListIterator<T> q) { return itptr != q.itptr; }

    T& operator*() { return itptr->data; }
};

#endif