#ifndef ORD_ARRLIST_H
#define ORD_ARRLIST_H

#include "AbstractList.h"
        
class OrderedArrayList : public AbstractList {

private:
    int* array;
    int capacity;
    int currentPos;

    // defined by me
    int binarySearch(int data);
    int binarySearchFindFirstOccurance(int data);
    void growArray();

public:
    OrderedArrayList();
    OrderedArrayList(int initialCapacity) ;
   
    virtual bool add(int data) ;
    virtual bool add(int index, int data) ;
    virtual void clear() ;
    virtual bool contains(int data) ;
    virtual int  get(int index) ;
    virtual int  indexOf(int data) ;
    virtual bool isEmpty() ;
    virtual int  remove(int index) ;
    virtual bool removeAll(int data) ;
    virtual int  size() ;
    virtual void trimToSize() ;

    //remove later
    // virtual void print() ;
};
#endif
