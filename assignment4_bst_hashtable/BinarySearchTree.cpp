// BinarySearchTree.cpp
// Author: Bryan Zublin
// ID: 828354677

#include "BinarySearchTree.h"
#include <cstddef>
#include <iostream>
#include <utility>

namespace BST_NS {

// copy ctor
template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& other) {
    this = other;
}

// dtor
template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
    makeEmpty();
}

// helper method
// binary search for a node, return it and its parent if found, else return
// NULL
template <class T>
std::pair<TreeNode<T>*, TreeNode<T>*> BinarySearchTree<T>::bSearch(T item) const {

    TreeNode<T>* curr = root;
    TreeNode<T>* prev = NULL;

    // search through tree for node with item
    while (curr != NULL) {
        if (item == curr->data) {  // item found
            return std::make_pair(curr, prev);
        } else if (item < curr->data) {
            prev = curr;
            curr = curr->leftLink;

        } else {
            prev = curr;
            curr = curr->rightLink;
        }
    }

    return std::make_pair(nullptr, nullptr);
}

// insert an item to the tree
template <class T>
void BinarySearchTree<T>::insert(T item) {

    if (root == NULL) {  // condition: tree is empty
        // std::cout << "    adding new root " << item << std::endl;
        root = new TreeNode<T>(item, NULL, NULL);
        tree_size++;
        return;
    }

    // condition: tree is not empty
    TreeNode<T>* curr = root;

    while (curr != NULL) {
        if (item < curr->data) {  // item is less than than curr

            // see if curr's left child is free. else, continue down
            if (curr->leftLink == NULL) {
                curr->leftLink = new TreeNode<T>(item, NULL, NULL);
                curr = NULL;
            } else {
                curr = curr->leftLink;
            }

        } else {  // item is greater than than curr

            // see if curr's right child is free. else, continue down
            if (curr->rightLink == NULL) {
                curr->rightLink = new TreeNode<T>(item, NULL, NULL);
                curr = NULL;
            } else {
                curr = curr->rightLink;
            }
        }
    }
    // std::cout << "    add " << item << " new size " << tree_size << std::endl;
    tree_size++;  // inc tree_size
}

// remove an item from the tree
template <class T>
void BinarySearchTree<T>::remove(T item) {

    // binary search through tree for node to remove, and its parent
    std::pair<TreeNode<T>*, TreeNode<T>*> nodePair = bSearch(item);
    TreeNode<T>* node = nodePair.first;
    TreeNode<T>* parent = nodePair.second;
    // if node not found, exit
    if (node == NULL) {
        // std::cout << "node not found for removal" << std::endl;
        return;
    }

    // std::cout << (parent == nullptr) << " REMOVING node= " << node->data << "  " <<
    // std::ends;

    if (node->leftLink == NULL && node->rightLink == NULL) {  // if node is a leaf
        // std::cout << "del leaf" << std::endl;
        if (parent == NULL) {  // if node is root
            // std::cout << "rootrootroot" << std::endl;
            delete node;
            root = NULL;
            tree_size--;
        } else {
            if (parent->leftLink == node) {  // parent adopts deleted node's left child
                parent->leftLink = NULL;
            } else {
                parent->rightLink = NULL;
            }
            delete node;
            node = NULL;
            tree_size--;
        }
    } else if (node->leftLink != NULL &&
               node->rightLink == NULL) {  // node has only left child
        // std::cout << "del leftkid, leftkid is " << node->leftLink->data << std::endl;
        if (parent == NULL) {  // if root, make leftchild new root
            root = node->leftLink;
        } else {
            if (parent->leftLink == node) {  // parent adopts deleted node's left child
                parent->leftLink = node->leftLink;
            } else {
                parent->rightLink = node->leftLink;
            }
        }
        delete node;
        node = NULL;
        tree_size--;
    } else if (node->rightLink != NULL &&
               node->leftLink == NULL) {  // node has only right child
        // std::cout << "del rightkid, rightkid is " << node->rightLink->data <<
        // std::endl;
        if (parent == NULL) {  // if root, make rightchild new root
            root = node->rightLink;
        } else {
            if (parent->leftLink == node) {  // parent adopt deleted node's right child
                parent->leftLink = node->rightLink;
            } else {
                parent->rightLink = node->rightLink;
            }
        }
        delete node;
        node = NULL;
        tree_size--;
    } else {  // node has 2 children
              // need to find and swap w/ successor, which is smallest
              // node of right subtree
        // std::cout << "del with succ " << node->rightLink->data << std::endl;

        TreeNode<T>* succ = node->rightLink;

        while (succ->leftLink != NULL) {
            succ = succ->leftLink;
        }
        // swap node and successor, then del successor
        int tempSuccData = succ->data;
        remove(succ->data);
        node->data = tempSuccData;
    }
    // std::cout << "  Bruh  " << tree_size << std::endl;
}

// check if an item exists in the tree
template <class T>
bool BinarySearchTree<T>::inTree(T item) const {
    return bSearch(item).first != NULL;
}

// overloading assignment operator
template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T> other) {
    other = copyTree(root);
    other.tree_size = tree_size;
}

// empty the tree
template <class T>
void BinarySearchTree<T>::makeEmpty() {
    deleteTree(root);
    root = NULL;
}

// helper method
// recursively delete tree
template <class T>
void BinarySearchTree<T>::deleteTree(TreeNode<T>* node) {
    if (node != NULL) {
        deleteTree(node->leftLink);
        deleteTree(node->rightLink);
        //        std::cout << "deleteTree: deleting " << node->data << std::endl;
        delete node;
        node = NULL;
        tree_size--;
    }
}

// helper method
// copy tree
template <class T>
BinarySearchTree<T> copyTree(BinarySearchTree<T> tree) {
    // base case: no more nodes to traverse preorder
    if (tree == NULL) {
        return NULL;
    } else {
        TreeNode<T>* newTree = new TreeNode<T>(tree.data, copyTree(tree->leftLink),
                                               copyTree(tree.rightLink));

        return newTree;
    }
}

// pre-order traversal (prints to stdout)
template <class T>
void BinarySearchTree<T>::preOrderShow() const {
    recursivePreOrderShow(root);
}

// helper function for recursive preorder
template <class T>
void BinarySearchTree<T>::recursivePreOrderShow(TreeNode<T>* subTreeRoot) const {
    if (subTreeRoot != NULL) {
        std::cout << subTreeRoot->data << " ";
        recursivePreOrderShow(subTreeRoot->leftLink);
        recursivePreOrderShow(subTreeRoot->rightLink);
    }
}

// in-order traversal (prints to stdout)
template <class T>
void BinarySearchTree<T>::inOrderShow() const {
    recursiveInOrderShow(root);
}

// helper function for recursive preorder
template <class T>
void BinarySearchTree<T>::recursiveInOrderShow(TreeNode<T>* subTreeRoot) const {
    if (subTreeRoot != NULL) {
        recursiveInOrderShow(subTreeRoot->leftLink);
        std::cout << subTreeRoot->data << " ";
        recursiveInOrderShow(subTreeRoot->rightLink);
    }
}

// post-order traversal (prints to stdout)
template <class T>
void BinarySearchTree<T>::postOrderShow() const {
    recursivePostOrderShow(root);
}

// helper function for recursive preorder
template <class T>
void BinarySearchTree<T>::recursivePostOrderShow(TreeNode<T>* subTreeRoot) const {
    if (subTreeRoot != NULL) {
        recursivePostOrderShow(subTreeRoot->leftLink);
        recursivePostOrderShow(subTreeRoot->rightLink);
        std::cout << subTreeRoot->data << " ";
    }
}

// return size of tree
template <class T>
int BinarySearchTree<T>::size() const {
    return tree_size;
}

// return height of tree
template <class T>
int BinarySearchTree<T>::height() {
    return getTreeHeight(root);
}

// helper function: recursively find tree height from node
template <class T>
int BinarySearchTree<T>::getTreeHeight(TreeNode<T>* node) {
    // base case: no more subtrees left to traverse
    if (node == NULL) {
        return 0;
    }
    int leftHeight = getTreeHeight(node->leftLink);
    int rightHeight = getTreeHeight(node->rightLink);

    if (leftHeight > rightHeight)
        return (1 + leftHeight);
    else
        return (1 + rightHeight);
}
}  // namespace BST_NS