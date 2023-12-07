#include "OrderedPQ.h"
#include "UnorderedPQ.h"
#include <iostream>

using namespace std;

int
main() {
    OrderedPQ queue(10);   // Either structure should perform the same
    // UnorderedPQ queue(10);      // Either structure should perform the same

    printf("Begin test\n\n");

    if (!queue.isEmpty())
        printf("1 ERROR: queue is empty\n");
    else
        printf("1  PASS: queue is empty\n");
    if (!queue.insert(10))
        printf("2 ERROR: insert largest item\n");
    else
        printf("2  PASS: insert largest item\n");
    if (!queue.remove())
        printf("3 ERROR: remove highest priority\n");
    else
        printf("3  PASS: remove highest priority\n");
    if (queue.contains(10))
        printf("4 ERROR: contains\n");
    else
        printf("4  PASS: contains\n");
    try {
        if (queue.remove())
            printf("5 ERROR: remove from empty queue\n");
    } catch (std::invalid_argument &e) {
        printf("5  PASS: caught exception remove when empty\n");
        printf("%s\n", e.what());
    } catch (std::exception &e) {
        printf("5 ERROR: caught unknown exception remove when empty\n");
        printf("%s\n", e.what());
    }

    printf("\nEnd test\n");
    // add more tests

    cout << "==========BEGINNING UNORDERED QUEUE TESTS==========\n";
    UnorderedPQ uqueue(2);
    cout << "size is: " << uqueue.size() << endl;
    cout << "isEmpty? " << uqueue.isEmpty() << endl;
    cout << uqueue.insert(5) << endl;
    cout << "size is: " << uqueue.size() << endl;
    cout << "isEmpty? " << uqueue.isEmpty() << endl;
    cout << uqueue.insert(10) << endl;
    cout << uqueue.insert(15) << endl;

    uqueue.print();   // debug method

    cout << "size is: " << uqueue.size() << endl;
    cout << uqueue.insert(3);
    uqueue.print();   // debug method
    cout << "size is: " << uqueue.size() << endl;
    cout << uqueue.insert(20) << endl;
    cout << "size is: " << uqueue.size() << endl;
    cout << uqueue.insert(25) << endl;
    cout << "size is: " << uqueue.size() << endl;
    cout << "removing index 2" << endl;
    uqueue.remove();
    uqueue.print();
    cout << "size is: " << uqueue.size() << endl;
    cout << "contains 20 " << uqueue.contains(20) << endl;
    cout << "contains 21 " << uqueue.contains(21) << endl;
    cout << "peek 0 " << uqueue.peek() << endl;
    cout << "peek 3 " << uqueue.peek() << endl;
    uqueue.print();
    try {
        cout << "peek 100 " << uqueue.peek() << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    try {
        cout << "remove 100 " << uqueue.remove() << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    try {
        cout << "add 100 " << uqueue.insert(100) << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    cout << endl << endl << "----deleteAll test----" << endl;
    uqueue.clear();
    uqueue.insert(1);
    uqueue.insert(2);
    uqueue.insert(3);
    uqueue.insert(3);
    uqueue.insert(3);
    uqueue.insert(4);
    uqueue.insert(3);
    uqueue.insert(3);
    uqueue.insert(6);
    uqueue.insert(5);
    uqueue.insert(3);
    uqueue.insert(3);
    uqueue.print();
    uqueue.deleteAll(3);
    uqueue.print();

    cout << "Unordered Tests Passed\n";
    cout << "==========BEGINNING ORDERED QUEUE TESTS==========\n";
    OrderedPQ oqueue(10);
    cout << "size is: " << oqueue.size() << endl;
    cout << "isEmpty? " << oqueue.isEmpty() << endl;
    cout << oqueue.insert(5) << endl;
    oqueue.print();   // debug method

    cout << "size is: " << oqueue.size() << endl;
    cout << "isEmpty? " << oqueue.isEmpty() << endl;
    cout << oqueue.insert(10) << endl;
    oqueue.print();   // debug method

    cout << oqueue.insert(15) << endl;
    oqueue.print();   // debug method
    cout << "size is: " << oqueue.size() << endl;
    cout << oqueue.insert(2);
    oqueue.print();   // debug method
    cout << "size is: " << oqueue.size() << endl;
    cout << oqueue.insert(20) << endl;
    cout << "size is: " << oqueue.size() << endl;
    cout << oqueue.insert(25) << endl;
    cout << "size is: " << oqueue.size() << endl;
    cout << "removing index 2" << endl;
    oqueue.remove();
    oqueue.print();
    cout << "size is: " << oqueue.size() << endl;

    cout << "contains 20 " << oqueue.contains(20) << endl;
    cout << "contains 21 " << oqueue.contains(21) << endl;
    cout << "peek 0 " << oqueue.peek() << endl;
    cout << "peek 3 " << oqueue.peek() << endl;
    oqueue.print();
    try {
        cout << "peek 100 " << oqueue.peek() << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    try {
        cout << "remove 100 " << oqueue.remove() << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    try {
        cout << "add 100 " << oqueue.insert(100) << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    cout << endl << endl << "----deleteAll test----" << endl;
    oqueue.clear();
    oqueue.insert(1);
    oqueue.insert(2);
    oqueue.insert(3);
    oqueue.insert(3);
    oqueue.insert(3);
    oqueue.insert(4);
    oqueue.insert(5);
    oqueue.insert(6);
    oqueue.print();
    cout << endl;
    oqueue.deleteAll(3);
    oqueue.print();
    return 0;
}