//
// Created by hauthorn on 3/10/17.
//
#include <functional>
#include <vector>
#include <queue>
#include "BaseHeap.cpp"

class QueueHeap : public BaseHeap {
private:
    priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int> > q;

protected:
    void minHeapify(unsigned int i) {
        // Nothing
    }

    void insert(unsigned int key) override {
        q.push(key);
    }

    // Not used
    unsigned int parent(unsigned int index) override {
        return 0;
    }

    void heapDecreaseKey(unsigned int index, unsigned int key) override {
        // Nothing
    }

public:
    unsigned int heapExtractMin() override {
        unsigned int min = q.top();
        q.pop();
        return min;
    }

    void buildHeap(unsigned int *array, unsigned int size) {

        for (int i = 0; i < size; ++i) {
            q.push(array[i]);
        }
    }
};
