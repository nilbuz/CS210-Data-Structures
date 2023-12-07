#include "OrderedArrayList.h"
#include "UnorderedArrayList.h"
#include <iostream>
using namespace std;
int
main() {
    UnorderedArrayList list(2);
    cout << "size is: " << list.size() << endl;
    cout << "isEmpty? " << list.isEmpty() << endl;
    cout << list.add(5) << endl;
    cout << "size is: " << list.size() << endl;
    cout << "isEmpty? " << list.isEmpty() << endl;
    cout << list.add(10) << endl;
    cout << list.add(15) << endl;

    // list.print();   // debug method

    cout << "size is: " << list.size() << endl;
    cout << list.add(3, 6);
    // list.print();   // debug method
    cout << "size is: " << list.size() << endl;
    cout << list.add(20) << endl;
    cout << "size is: " << list.size() << endl;
    cout << list.add(25) << endl;
    cout << "size is: " << list.size() << endl;
    cout << "removing index 2" << endl;
    list.remove(2);
    // list.print();
    cout << "size is: " << list.size() << endl;
    cout << "indexOf 20 " << list.indexOf(20) << endl;
    cout << "indexOf 21 " << list.indexOf(21) << endl;
    cout << "contains 20 " << list.contains(20) << endl;
    cout << "contains 21 " << list.contains(21) << endl;
    cout << "get 0 " << list.get(0) << endl;
    cout << "get 3 " << list.get(3) << endl;
    // list.print();
    try {
        cout << "get 100 " << list.get(100) << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    try {
        cout << "remove 100 " << list.remove(100) << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    try {
        cout << "add 100 " << list.add(100, 100) << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    cout << endl << endl << "----deleteAll test----" << endl;
    list.clear();
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(3);
    list.add(3);
    list.add(4);
    list.add(3);
    list.add(3);
    list.add(6);
    list.add(5);
    list.add(3);
    list.add(3);
    // list.print();
    list.removeAll(3);
    // list.print();

    cout << "Unordered Tests Passed\n";
    cout << "==========BEGINNING ORDERED LIST TESTS==========\n";
    // OrderedArrayList ol;
    OrderedArrayList ol(10);
    cout << "size is: " << ol.size() << endl;
    cout << "isEmpty? " << ol.isEmpty() << endl;
    cout << ol.add(5) << endl;
        ol.print();   // debug method

    cout << "size is: " << ol.size() << endl;
    cout << "isEmpty? " << ol.isEmpty() << endl;
    cout << ol.add(10) << endl;
        ol.print();   // debug method

    cout << ol.add(15) << endl;
    ol.print();   // debug method
    cout << "size is: " << ol.size() << endl;
    cout << ol.add(2, 10);
    ol.print();   // debug method
    cout << "size is: " << ol.size() << endl;
    cout << ol.add(20) << endl;
    cout << "size is: " << ol.size() << endl;
    cout << ol.add(25) << endl;
    cout << "size is: " << ol.size() << endl;
    cout << "removing index 2" << endl;
    ol.remove(2);
    ol.print();
    cout << "size is: " << ol.size() << endl;
    cout << "indexOf 20 " << ol.indexOf(20) << endl;
    cout << "indexOf 5 " << ol.indexOf(5) << endl;

    cout << "indexOf 21 " << ol.indexOf(21) << endl;
    cout << "contains 20 " << ol.contains(20) << endl;
    cout << "contains 21 " << ol.contains(21) << endl;
    cout << "get 0 " << ol.get(0) << endl;
    cout << "get 3 " << ol.get(3) << endl;
    ol.print();
    try {
        cout << "get 100 " << ol.get(100) << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    try {
        cout << "remove 100 " << ol.remove(100) << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    try {
        cout << "add 100 " << ol.add(100, 100) << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    cout << endl << endl << "----deleteAll test----" << endl;
    ol.clear();
    ol.add(1);
    ol.add(2);
    ol.add(3);
    ol.add(3);
    ol.add(3);
    ol.add(4);
    ol.add(5);
    ol.add(6);
    ol.print();
    cout << endl;
    ol.removeAll(3);
    ol.print();

    return 0;
}