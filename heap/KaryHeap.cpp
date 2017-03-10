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
            if (c < size_of_array && array[c] < array[index]) {
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

    void buildHeap(unsigned int *array, unsigned int size) {
        this->size_of_array = size;
        this->array = array;

        unsigned int index_of_last_node = (size - 1) / K;

        for (int i = index_of_last_node; i >= 0; i--) {
            minHeapify((unsigned int) i);
        }
    }
};