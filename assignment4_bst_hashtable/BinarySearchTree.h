// Bryan Zublin
// 828354677

// BinarySearchTree.h:	Header file for BinaryBinarySearchTree.cpp
// The only way to insert data in a tree is with the insert function, thus 
// satisfying the BST rule giving it a well behaved ordering to the type T.

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream> // for std::cout
#include <utility>

namespace BST_NS
{
	template<class T>
	class BinarySearchTree; //forward declaration

	template<class T>
	class TreeNode {
		public:
			TreeNode( ) : data(NULL), leftLink(NULL), rightLink(NULL) {}
			TreeNode(T theData, TreeNode<T>* left, TreeNode<T>* right)
				: data(theData), leftLink(left), rightLink(right) {}
			friend class BinarySearchTree<T>;
		private:
			T data;
			TreeNode<T>* leftLink;
			TreeNode<T>* rightLink;
	};


	// supply the pre and post conditions for each method
	template<class T>
	class BinarySearchTree {
		private:
			TreeNode<T> *root;
			int tree_size;

			// mine
			std::pair<TreeNode<T>*, TreeNode<T>*> bSearch(T item) const;
			void deleteTree(TreeNode<T> *node);
			BinarySearchTree<T> copyTree(BinarySearchTree<T> tree);

			void recursivePreOrderShow(TreeNode<T>* subTreeRoot) const;
			void recursiveInOrderShow(TreeNode<T>* subTreeRoot) const;
			void recursivePostOrderShow(TreeNode<T>* subTreeRoot) const;

			int getTreeHeight(TreeNode<T>*);

		public:
			// default ctor
			BinarySearchTree() : root(NULL), tree_size(0) {}
			// copy ctor
			BinarySearchTree(const BinarySearchTree& other);
			// virtual dtor
			virtual ~BinarySearchTree();
			// insert an item to the tree
			void insert(T item); 
			// remove an item from the tree
			void remove(T item);
			// check if an item exists in the tree
			bool inTree(T item) const;
			// overloading assignment operator
			BinarySearchTree& operator=(const BinarySearchTree other);
			// empty the tree
			void makeEmpty();
			// pre-order traversal (prints to stdout)
			void preOrderShow() const;
			// in-order traversal (prints to stdout)
			void inOrderShow() const;
			// post-order traversal (prints to stdout)
			void postOrderShow() const;
			// return size of tree
			int size() const;
			// return height of tree
			int height();
	};

} // BST_NS 

#endif
