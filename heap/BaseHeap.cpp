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

protected:
    virtual void minHeapify(unsigned int i) = 0;

public:

    virtual unsigned int heapExtractMin() {
        unsigned int min = array[0];

        array[0] = array[size_of_array - 1];
        size_of_array = size_of_array - 1;

        minHeapify(0);

        return min;
    }

    virtual void insert(unsigned int key) = 0;

    virtual void buildHeap(unsigned int *array, unsigned int size) = 0;
};

#endif