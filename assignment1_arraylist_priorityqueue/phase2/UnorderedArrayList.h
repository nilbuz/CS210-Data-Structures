#ifndef UNORD_ARRLIST_H
#define UNORD_ARRLIST_H

#include "AbstractList.h"
        
class UnorderedArrayList : public AbstractList {

private:
    int* array;
    int capacity;
    int currentPos;

public:
    UnorderedArrayList();
    UnorderedArrayList(int initialCapacity) ;

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
};
#endif
