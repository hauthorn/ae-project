//
// Created by hauthorn on 3/10/17.
//
#include <functional>
#include <vector>
#include <queue>
#include "BaseHeap.cpp"

class QueueHeap: public BaseHeap {
private:
    priority_queue<unsigned int,vector<unsigned int>,greater<unsigned int> > q;

public:
    unsigned int heapExtractMin() {
        unsigned int min = q.top();
        q.pop();
        return min;
    }

    void insert(unsigned int key) {
        q.push(key);
    }

    void buildHeap(unsigned int *array, unsigned int size) {

        for (int i = 0; i < size; ++i) {
            q.push(array[i]);
        }
    }
};
