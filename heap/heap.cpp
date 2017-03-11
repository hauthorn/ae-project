#include <iostream>
#include "BaseHeap.cpp"

using namespace std;

class BinaryHeap : public BaseHeap {
private:
    unsigned int left(unsigned int i) {
        return 2 * i + 1;
    }

    unsigned int right(unsigned int i) {
        return 2 * i + 2;
    }

protected:
    unsigned int parent(unsigned int i) {
        return (i - 1) / 2;
    }

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
    unsigned int heapExtractMin() {
        unsigned int min = array[0];
        array[0] = array[size_of_array - 1];
        size_of_array = size_of_array - 1;
        minHeapify(0);
        return min;
    }

    /**
     * Inserts the key at the bottom of the heap, and starts bubbling up
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
        this->array = array;

        for (int i = size / 2; i >= 0; i--) {
            minHeapify((unsigned int) i);
        }
    }
};