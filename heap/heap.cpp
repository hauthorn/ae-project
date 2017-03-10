#include <iostream>
#include "BaseHeap.cpp"

using namespace std;

class Heap : public BaseHeap {
private:
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

protected:
    void minHeapify(unsigned int i) {
        unsigned int l = left(i);
        unsigned int r = right(i);
        unsigned int smallest;

        if (l < size_of_array && array[l] < array[i]) {
            smallest = l;
        } else {
            smallest = i;
        }
        if (r < size_of_array && array[r] < array[smallest]) {
            smallest = r;
        }
        if (smallest != i) {
            unsigned int temp = array[i];
            array[i] = array[smallest];
            array[smallest] = temp;
            minHeapify(smallest);
        }
    }


public:
    /**
     * Inserts the key at the bottom of the heap, and starts bubling up
     * @param key
     */
    void insert(unsigned int key) {
        size_of_array++;
        array[size_of_array] = MAX_VALUE;
        heapDecreaseKey(size_of_array, key);
    }

    /**
     * Constructs our heap from the array
     * @param array
     * @param size
     */
    void buildHeap(unsigned int *array, unsigned int size) {
        this->size_of_array = size;
        this->array = array;

        for (int i = size / 2; i >= 0; i--) {
            minHeapify((unsigned int) i);
        }
    }
};