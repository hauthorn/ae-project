//
// Created by hauthorn on 3/10/17.
//
#include "BaseHeap.cpp"

class KaryHeap : public BaseHeap {
private:
    unsigned int K;

    unsigned int child(unsigned int index, unsigned int k) {
        return (K * index) + k;
    }

protected:

    /**
     * Compares the index to all it's K children, replacing with the smallest if smaller than index
     * @param array
     * @param i
     */
    void minHeapify(unsigned int index) {
        unsigned int smallest = index;

        for (unsigned int i = 1; i <= K; ++i) {
            unsigned int c = child(index, i);
            if (c < size_of_array && array[c] < array[smallest]) {
                smallest = c;
            }
        }

        if (smallest != index) {
            unsigned int temp = array[index];
            array[index] = array[smallest];
            array[smallest] = temp;
            minHeapify(smallest);
        }
    }


    unsigned int parent(unsigned int index) {
        return (index - 1) / K;
    }


public:
    KaryHeap(unsigned int K) : K(K) {}

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