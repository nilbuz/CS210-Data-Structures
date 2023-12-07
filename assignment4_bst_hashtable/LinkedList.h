// Bryan Zublin
// 828354677

// This is the header file LinkedList.h. This contains type definitions and
// function declarations for manipulating a linked list to store data of any type T.
// The linked list is given as a pointer of type Node<T>* which points to the
// head (first) node of the list. The implementation of the functions are given
// in the file LinkedList.cpp.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace LinkedListNS {
template <class T>
class Node {
  public:
    Node(const T& theData, Node<T>* theLink) : data(theData), link(theLink) {}
    Node<T>* getLink() const { return link; }
    const T& getData() const { return data; }
    void setData(const T& theData) { data = theData; }
    void setLink(Node<T>* pointer) { link = pointer; }

  private:
    T data;
    Node<T>* link;
};

// Precondition: The pointer variable head points to
// the head of a linked list.
// Postcondition: A new node containing theData
// has been added at the head of the linked list.
template <class T>
void headInsert(Node<T>*& head, const T& theData);

// Precondition: afterMe points to a node in a linked list.
// Postcondition: A new node containing theData
// has been added after the node pointed to by afterMe.
template <class T>
void insert(Node<T>* afterMe, const T& theData);

// Precondition: The pointers before point to nodes that has
// at least one node after it in the linked list.
// Postcondition: The node after the node pointed to by before
// has been removed from the linked list and its storage
// returned to the freestore.
template <class T>
void deleteNode(Node<T>* before);

// Precondition: The pointers head points to the first
// node in a linked list; with at least one node.
// Postcondition: The node pointed to by head has been removed
// for the linked list and its storage returned to the freestore.
template <class T>
void deleteFirstNode(Node<T>*& head);

// Precondition: The pointer head points to the head of a linked list.
// The pointer variable in the last node is NULL. head (first) node
// head (first) node has been defined for type T.
//(== is used as the criterion for being equal).
// If the list is empty, then head is NULL.
// Returns a pointer that points to the first node that
// is equal to the target. If no node equals the target,
// the function returns NULL.
template <class T>
Node<T>* search(Node<T>* head, const T& target);

// testing method
// template <class T>
// void printList(Node<T>*& head);

}  // namespace LinkedListNS

#endif  // LINKEDLIST_H
