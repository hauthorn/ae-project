//
// Created by hauthorn on 3/10/17.
//
#include "../BaseHeap.cpp"

class EightHeap : public BaseHeap {
private:
    const unsigned int K = 8;
protected:
    /**
     * Compares the index to all it's 8 children, replacing with the smallest if smaller than index
     * @param array
     * @param i
     */
    void minHeapify(unsigned int index) {
        unsigned int smallest = index;
        unsigned int indexVal = array[index];

        unsigned int c_1 = K * index + 1;
        unsigned int c_2 = K * index + 2;
        unsigned int c_3 = K * index + 3;
        unsigned int c_4 = K * index + 4;
        unsigned int c_5 = K * index + 5;
        unsigned int c_6 = K * index + 6;
        unsigned int c_7 = K * index + 7;
        unsigned int c_8 = K * index + 8;

        if (c_1 < size_of_array && array[c_1] < array[smallest]) {
            smallest = c_1;
        }
        if (c_2 < size_of_array && array[c_2] < array[smallest]) {
            smallest = c_2;
        }
        if (c_3 < size_of_array && array[c_3] < array[smallest]) {
            smallest = c_3;
        }
        if (c_4 < size_of_array && array[c_4] < array[smallest]) {
            smallest = c_4;
        }
        if (c_5 < size_of_array && array[c_5] < array[smallest]) {
            smallest = c_5;
        }
        if (c_6 < size_of_array && array[c_6] < array[smallest]) {
            smallest = c_6;
        }
        if (c_7 < size_of_array && array[c_7] < array[smallest]) {
            smallest = c_7;
        }
        if (c_8 < size_of_array && array[c_8] < array[smallest]) {
            smallest = c_8;
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