#include <iostream>
#include <limits>

using namespace std;

class Heap {
public:
    unsigned int *array;
    unsigned int size_of_array;
    unsigned int max = numeric_limits<int>::max();

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

    unsigned int heapExtractMin() {
        unsigned int min = array[0];

        array[0] = array[size_of_array-1];
        size_of_array = size_of_array - 1;

        minHeapify(array, 0);

        return min;
    }

    unsigned int left(unsigned int i) {
        return 2 * i + 1;
    }

    unsigned int right(unsigned int i) {
        return 2 * i + 2;
    }

    unsigned int parent(unsigned int i) {
        return i / 2;
    }

    void heapDecreaseKey(unsigned int *pInt, unsigned int array, unsigned int i) {

    }

    void minHeapInsert(unsigned int *array, unsigned int i) {
        size_of_array++;
        array[size_of_array] = max;
        heapDecreaseKey(array, size_of_array, i);
    }

    void buildHeap(unsigned int *array, unsigned int size) {
        this->size_of_array = size;

        for (int i = size / 2; i >= 0; i--) {
            minHeapify(array, (unsigned int) i);
        }

        this->array = array;
    }
};