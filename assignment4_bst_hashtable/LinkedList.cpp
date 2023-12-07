// LinkedList.cpp
// Author: Bryan Zublin
// ID: 828354677

#include "LinkedList.h"
#include <cstddef>
//#include <iostream>

namespace LinkedListNS {

// Precondition: The pointer variable head points to
// the head of a linked list.
// Postcondition: A new node containing theData
// has been added at the head of the linked list.
template <class T>
void headInsert(Node<T>*& head, const T& theData) {

    if (head == NULL) {   // if empty
        head = new Node<T>(theData, NULL);
    } else {
        Node<T>* newNode = new Node<T>(theData, head);
        newNode->setLink(head);
        head = newNode;
    }
}

// Precondition: afterMe points to a node in a linked list.
// Postcondition: A new node containing theData
// has been added after the node pointed to by afterMe.
template <class T>
void insert(Node<T>* afterMe, const T& theData) {
    Node<T>* newNode = new Node<T>(theData, afterMe->getLink());
    afterMe->setLink(newNode);
}

// Precondition: The pointers before point to nodes that has
// at least one node after it in the linked list.
// Postcondition: The node after the node pointed to by before
// has been removed from the linked list and its storage
// returned to the freestore.
template <class T>
void deleteNode(Node<T>* before) {
    Node<T>* nodeToDelete = before->getLink();
    before->setLink(nodeToDelete->getLink());
    delete nodeToDelete;
}

// Precondition: The pointers head points to the first
// node in a linked list with at least one node.
// Postcondition: The node pointed to by head has been removed
// for the linked list and its storage returned to the freestore.
template <class T>
void deleteFirstNode(Node<T>*& head) {

    if (head->getLink() == NULL) {   // if only 1 node in list
        delete head;
    } else {
        Node<T>* nodeToDelete = head;
        head = head->getLink();
        delete nodeToDelete;
    }
}

// Precondition: The pointer head points to the head of a linked list.
// The pointer variable in the last node is NULL.
// head (first) node has been defined for type T.
//(== is used as the criterion for being equal).
// If the list is empty, then head is NULL.
// Returns a pointer that points to the first node that
// is equal to the target. If no node equals the target,
// the function returns NULL.
template <class T>
Node<T>* search(Node<T>* head, const T& target) {
    if (head == NULL) return NULL;   // if list empty

    Node<T>* curr = head;
    while (curr != NULL) {
        if (curr->getData() == target) return curr;
        curr = curr->getLink();
    }
    return NULL;
}

// template <class T>
// void printList(Node<T>*& head) {
//     if (head == NULL) return;   // if list empty

//     Node<T>* curr = head;
//     while (curr != NULL) {
//         std::cout << curr->getData() << " ";
//         curr = curr->getLink();
//     }
//     std::cout << std::endl;
// }

}   // namespace LinkedListNS