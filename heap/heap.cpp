
#include <array>
#include <vector>
#include <iostream>

using namespace std;

class Heap {
private:
    vector<unsigned int> array;

public:
    void minHeapify(vector<unsigned int> vector, int i) {
        unsigned int l = left(i);
        unsigned int r = right(i);
        unsigned int smallest;

        if (l < vector.size() && vector[l] < vector[i]) {
            smallest = l;
        } else {
            smallest = i;
        }
        if (r < vector.size() && vector[r] < vector[smallest]) {
            smallest = r;
        }
        if (smallest != i) {
            unsigned int temp = vector[i];
            vector[i] = vector[smallest];
            vector[smallest] = temp;
            minHeapify(vector, smallest);
        }
    }

    unsigned int heapExtractMin() {
        unsigned int &min = array[0];

        array[0] = array.back();
        array.pop_back();

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


    void buildHeap(vector<unsigned int> array) {
        for(int i = array.size()/2; i >= 0; i--) {

            cout << "minHeapify: " << i << endl;
            minHeapify(array, i);
        }

        this->array = array;

    }
};