#include <iostream>
#include "BaseHeap.cpp"

using namespace std;

class Heap : public BaseHeap {
private:
    void minHeapify(unsigned int *array, unsigned int i) {
        unsigned int l = left(i);
        unsigned int r = right(i);
        unsigned int smallest;

        unsigned int left = array[l];
        unsigned int index = array[i];
        unsigned int right = array[r];

        if (l < size_of_array && left < index) {
            smallest = l;
        } else {
            smallest = i;
        }
        if (r < size_of_array && right < array[smallest]) {
            smallest = r;
        }
        if (smallest != i) {
            unsigned int temp = array[i];
            array[i] = array[smallest];
            array[smallest] = temp;
            minHeapify(array, smallest);
        }
    }

    unsigned int left(unsigned int i) {
        return 2 * i + 1;
    }

    unsigned int right(unsigned int i) {
        return 2 * i + 2;
    }

    unsigned int parent(unsigned int i) {
        return (i - 1) / 2;
    }

    /**
     * Decrease the key for this index
     * PRECONDITION: Key must be smaller than the value at index
     * @param index
     * @param key
     */
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
    unsigned int heapExtractMin() {
        unsigned int min = array[0];
        array[0] = array[size_of_array - 1];
        size_of_array = size_of_array - 1;
        minHeapify(array, 0);
        return min;
    }

    /**
     * Inserts the key at the bottom of the heap, and starts bubling up
     * @param key
     */
    void insert(unsigned int key) {
        array[size_of_array] = MAX_VALUE;
        heapDecreaseKey(size_of_array, key);
        size_of_array++;
    }

    /**
     * Constructs our heap from the array
     * @param array
     * @param size
     */
    void buildHeap(unsigned int *array, unsigned int size) {
        this->size_of_array = size;

        for (int i = size / 2; i >= 0; i--) {
            minHeapify(array, (unsigned int) i);
        }

        this->array = array;
    }
};