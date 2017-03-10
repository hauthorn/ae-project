//
// Created by frederik on 3/8/17.
//

#include <iostream>
#include <random>
#include <chrono>
#include <queue>
#include "heap.cpp"
#include "QueueHeap.cpp"


using namespace std;

const unsigned int size = 1000;
unsigned int* v = new unsigned int[size];

int main() {

    vector<BaseHeap*> algorithms(0);
    algorithms.push_back(new Heap);
    algorithms.push_back(new QueueHeap);

    unsigned seed = (unsigned int) std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(5,100);

    for (int i = 0; i < size; i++) {
        unsigned int value = (unsigned int) distribution(generator);
        value += distribution(generator);
        v[i] = value;
    }

    for (BaseHeap *h : algorithms) {
        h->buildHeap(v, size);
    }


    // Do size / 2 extracts
    for (int j = 0; j < size / 2; ++j) {
        unsigned int preResult = 0;

        for (BaseHeap *h : algorithms) {
            if (preResult == 0) {
                preResult = h->heapExtractMin();
            }
            else {
                unsigned int min = h->heapExtractMin();
                if (min != preResult) {
                    fprintf(stderr, "Results differ between algorithms!\n");
                }
                preResult = min;
            }
        }
    }

    // Do size / 2 inserts
    for (int k = 0; k < size / 2; ++k) {
        unsigned int value = (unsigned int) distribution(generator);

        for (BaseHeap *h : algorithms) {
            h->insert(value);
        }
    }

    // Do size / extracts
    for (int j = 0; j < size / 2; ++j) {
        unsigned int preResult = 0;

        for (BaseHeap *h : algorithms) {
            if (preResult == 0) {
                preResult = h->heapExtractMin();
            }
            else {
                unsigned int min = h->heapExtractMin();
                if (min != preResult) {
                    fprintf(stderr, "Results differ between algorithms!\n");
                }
                preResult = min;
            }
        }
    }

    return 0;
}