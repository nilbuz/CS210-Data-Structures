#include "BinarySearchTree.cpp"
// include "BinarySearchTree.h"
#include "BinarySearchTree.h"
#include "LinkedList.cpp"
// #include "LinkedList.h"
#include "HashTable.cpp"
// #include "HashTable.h"

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
using namespace BST_NS;
using namespace LinkedListNS;
using namespace HashTableNS;

int main() {

    cout << "______Testing BST______" << endl;
    BinarySearchTree<int>* bst = new BinarySearchTree<int>();

    cout << "___Testing traversals___" << endl;
    bst->insert(5);
    bst->insert(2);
    bst->insert(10);
    bst->insert(7);
    bst->insert(8);
    bst->insert(12);
    // bst->preOrderShow();
    // cout << "preorder" << endl;
    // bst->inOrderShow();
    // cout << "inorder" << endl;
    // bst->postOrderShow();
    // cout << "postorder" << endl;
    cout << "tree height, size : " << bst->height() << " " << bst->size() << endl;
    bst->makeEmpty();
    cout << "tree height, size : " << bst->height() << " " << bst->size() << endl;
    cout << "_______________" << endl;

    bst->insert(1);
    bst->insert(2);
    bst->insert(3);
    cout << "___Testing removing nodes with only right children___" << endl;
    bst->remove(3);
    bst->remove(2);
    bst->remove(1);

    bst->insert(3);
    bst->insert(2);
    bst->insert(1);
    cout << "___Testing removing nodes with only left children___" << endl;
    bst->remove(2);
    bst->remove(3);

    bst->remove(1);

    cout << "bst tree height, size : " << bst->height() << " " << bst->size() << endl;
    bst->insert(5);
    cout << "bst tree height, size : " << bst->height() << " " << bst->size() << endl;
    bst->insert(2);
    cout << "bst tree height, size : " << bst->height() << " " << bst->size() << endl;
    bst->insert(10);
    cout << "bst tree height, size : " << bst->height() << " " << bst->size() << endl;
    bst->insert(7);
    cout << "bst tree height, size : " << bst->height() << " " << bst->size() << endl;
    bst->insert(8);
    cout << "bst tree height, size : " << bst->height() << " " << bst->size() << endl;
    bst->insert(12);
    cout << bst->size() << "___Testing removing nodes in a weird order___" << endl;
    bst->remove(8);
    cout << "bst tree height, size : " << bst->height() << " " << bst->size() << endl;
    bst->remove(10);
    cout << "bst tree height, size : " << bst->height() << " " << bst->size() << endl;
    bst->remove(5);
    bst->preOrderShow();
    cout << "bst tree height, size : " << bst->height() << " " << bst->size() << endl;

    // BinarySearchTree<int>* bst2 = new BinarySearchTree<int>();
    // bst2 = bst;
    // cout << "bst tree height, size : " << bst->height() << " " << bst->size() << endl;
    // cout << "bst2 tree height, size : " << bst2->height() << " " << bst2->size() << endl;
    // cout << "_______________" << endl;
    // bst->makeEmpty();

    /*
        cout << "______Testing LinkedList with int nodes______" << endl;

        typedef Node<int> IntNode;
        IntNode* list = new IntNode(1, NULL);
        headInsert(list, 1);
        cout << "headInsert 1" << endl;
        insert(list, 2);
        cout << "insert 1 2nd" << endl;
        insert(search(list, 2), 3);
        cout << "insert 3 after node 2" << endl;
        printList(list);
        deleteFirstNode(list);
        cout << "del first node" << endl;
        deleteNode(list);
        cout << "delnode after head" << endl;
        insert(list, 4);
        cout << "insert 4 2nd" << endl;
        printList(list);
        deleteNode(search(list, 4));
        cout << "delnode after 4" << endl;
        printList(list);

        cout << "______Finished testing LinkedList with int nodes______" <<
       endl;

        cout << "______Testing LinkedList with string nodes______" << endl;

        typedef Node<string> StringNode;
        StringNode* list2 = new StringNode("a", NULL);
        headInsert(list2, string("b"));
        cout << "headInsert b" << endl;
        insert(list2, string("c"));
        cout << "insert c 2nd" << endl;
        insert(search(list2, string("c")), string("d"));
        cout << "insert d after node c" << endl;
        printList(list2);
        deleteFirstNode(list2);
        cout << "del first node" << endl;
        deleteNode(list2);
        cout << "delnode after head" << endl;
        insert(list2, string{"e"});
        cout << "insert e 2nd" << endl;
        printList(list2);
        deleteNode(search(list2, string("e")));
        cout << "delnode after e" << endl;
        printList(list2);

        cout << "______Finished testing LinkedList with string nodes______" <<
       endl;

        cout << "______Testing HashTable______" << endl;
        HashTable* table = new HashTable();
        table->put("asdf");
        table->put("dude");
        table->put("ahahahahahaha");
        table->put("a");
        table->put("");
        table->put("b");
        table->put("c");

        cout << "contains 'asdf' " << table->containsString("asdf") << endl;
        cout << "contains 'poo' " << table->containsString("poo") << endl;
        cout << "contains 'a' " << table->containsString("a") << endl;

        delete table;
    */
    return 0;
}