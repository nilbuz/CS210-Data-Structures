# CS 210 Spring 2023
# p1 configuration
# Usage:  
#   make ListADT.o
#   make p1

CC=g++
CFLAGS=-g -Wall -std=c++11

p1: p1tester.cpp OrderedPQ.o UnorderedPQ.o UnorderedArrayList.o OrderedArrayList.o
	$(CC) $(CFLAGS) -o p1 p1tester.cpp OrderedPQ.o UnorderedPQ.o OrderedArrayList.o UnorderedArrayList.o

UnorderedPQ.o: UnorderedPQ.h UnorderedPQ.cpp UnorderedArrayList.o
	$(CC) $(CFLAGS) -c UnorderedPQ.cpp UnorderedArrayList.o

OrderedPQ.o: OrderedPQ.h OrderedPQ.cpp OrderedArrayList.o
	$(CC) $(CFLAGS) -c OrderedPQ.cpp OrderedArrayList.o

UnorderedArrayList.o: UnorderedArrayList.cpp UnorderedArrayList.h AbstractList.h
	$(CC) $(CFLAGS) -c UnorderedArrayList.cpp 

OrderedArrayList.o: OrderedArrayList.cpp OrderedArrayList.h AbstractList.h
	$(CC) $(CFLAGS) -c OrderedArrayList.cpp 

clean:
	rm *.o 

cleanall:
	rm *.o p1

