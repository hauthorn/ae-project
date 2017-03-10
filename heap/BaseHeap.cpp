//
// Created by hauthorn on 3/10/17.
//
#include <limits>
#include <array>

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

    virtual unsigned int parent(unsigned int index) = 0;

    virtual /**
     * Decrease the key for this index
     * PRECONDITION: Key must be smaller than the value at index
     * @param index
     * @param key
     */
//    void heapDecreaseKey(unsigned int index, unsigned int key) {
//        array[index] = key;
//
//        unsigned int p = parent(index);
//
//        // Continue upwards until we reach root
//        while (p >= 0 && p < size_of_array) {
//            // the parent is bigger than key
//            if (array[p] > key) {
//                swap(array[index], array[p]);
//                index = p;
//                p = parent(index);
//            }
//            else
//                break;
//        }
//    }

    void heapDecreaseKey(unsigned int index, unsigned int key) {
        array[index] = key;

        // Continue upwards until the parent is smaller than key
        while (index > 0 && array[parent(index)] > key) {
            // exchange
            unsigned int tmp = array[index];
            array[index] = array[parent(index)];
            array[parent(index)] = tmp;
            // Decrease index
            index = parent(index);
        }
    }

public:
    virtual /**
     * Inserts the key at the bottom of the heap, and starts bubling up
     * @param key
     */
    void insert(unsigned int key) {
        size_of_array++;
        array[size_of_array] = MAX_VALUE;
        heapDecreaseKey(size_of_array, key);
    }

    virtual unsigned int heapExtractMin() {
        unsigned int min = array[0];

        array[0] = array[size_of_array - 1];
        size_of_array = size_of_array - 1;

        minHeapify(0);

        return min;
    }

    virtual void buildHeap(unsigned int *array, unsigned int size) = 0;
};

#endif