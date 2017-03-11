//
// Created by hauthorn on 3/10/17.
//
#include "BaseHeap.cpp"

class TernaryHeap : public BaseHeap {
private:
    const unsigned int K = 3;
protected:
    /**
     * Compares the index to all it's 3 children, replacing with the smallest if smaller than index
     * @param array
     * @param i
     */
    void minHeapify(unsigned int index) {
        unsigned int smallest = index;

        unsigned int l = K * index + 1;
        unsigned int m = K * index + 2;
        unsigned int r = K * index + 3;

        unsigned int indexVal = array[index];

        if (l < size_of_array && array[l] < array[smallest]) {
            smallest = l;
        }
        if (m < size_of_array && array[m] < array[smallest]) {
            smallest = m;
        }
        if (r < size_of_array && array[r] < array[smallest]) {
            smallest = r;
        }

        if (smallest != index) {
            array[index] = array[smallest];
            array[smallest] = indexVal;
            minHeapify(smallest);
        }
    }


    unsigned int parent(unsigned int index) {
        return (index - 1) / K;
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

    void buildHeap(unsigned int *array, unsigned int size) {
        this->size_of_array = size;
        this->array = array;

        unsigned int index_of_last_node = (size - 1) / K;

        for (int i = index_of_last_node; i >= 0; i--) {
            minHeapify((unsigned int) i);
        }
    }
};