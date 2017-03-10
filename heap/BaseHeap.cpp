//
// Created by hauthorn on 3/10/17.
//
#include <limits>

using namespace std;

#ifndef BASEHEAP
#define BASEHEAP


class BaseHeap {
protected:
    unsigned int *array;
    unsigned int size_of_array;
    const unsigned int MAX_VALUE = numeric_limits<unsigned int>::max();
public:

    virtual unsigned int heapExtractMin() = 0;

    virtual void insert(unsigned int key) = 0;

    virtual void buildHeap(unsigned int *array, unsigned int size) = 0;
};

#endif