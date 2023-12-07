#include "LinkedListPQ.h"
#include <iostream>
#include <stdexcept>

// Use iterator to view contents of linked list
template <typename T>
void
print(LinkedListPQ<T> pq) {
    std::cout << "List-> ";
    ListIterator<T> p;

    for (p = pq.first(); p != pq.end(); p++) {
        std::cout << *p << ' ' << std::endl;
    }
    std::cout << std::endl;
}

int
main() {
    std::cout << "penis" << std::endl;
    LinkedListPQ<int> intpq;
    std::cout << intpq.size() << std::endl;
    std::cout << intpq.isEmpty() << std::endl;
    std::cout << intpq.isFull() << std::endl;
    // intpq.clear();
    printf("inserting...\n");
    intpq.insert(10);
    std::cout << intpq.size() << std::endl;

    print(intpq);
    intpq.peek();
    if (intpq.size() != 1) std::cout << "ERROR: size should be 1\n";
    if (intpq.size() == 1) std::cout << "PASS: size should be 1\n";
    if (intpq.remove() == 10)
        std::cout << "PASS: removed 10\n";
    else
        std::cout << "ERROR: should have removed 10\n";
    intpq.insert(20);
    intpq.contains(20);
    intpq.insert(30);
    intpq.deleteAll(10);
    if (intpq.remove() == 20)
        std::cout << "PASS: removed 20\n";
    else
        std::cout << "ERROR: should have removed 20\n";

    // Insert more tests here
    return 0;
}
