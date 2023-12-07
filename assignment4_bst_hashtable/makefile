# makefile for program 4
# author: Bryan Zublin
# RED ID: 828354677
CC=g++
CFLAGS=-g -Wall -fcompare-debug-second -std=c++11
#CFLAGS=-g -Wall -std=c++11


p4: p4tester.cpp BinarySearchTree.o LinkedList.o HashTable.o
		$(CC) $(CFLAGS) -o p4 p4tester.cpp BinarySearchTree.o LinkedList.o 

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
		$(CC) $(CFLAGS) -c BinarySearchTree.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
		$(CC) $(CFLAGS) -c LinkedList.cpp

HashTable.o: HashTable.cpp HashTable.h
		$(CC) $(CFLAGS) -c HashTable.cpp

clean:
		rm *.o

cleanall:
		rm *.o p4
