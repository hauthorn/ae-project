//
// Created by frederik on 3/8/17.
//

#include <iostream>
#include <random>
#include <chrono>
#include <queue>
#include "heap.cpp"


using namespace std;

int main() {

    unsigned int size = 1000;
    unsigned int* v = new unsigned int[size];

    priority_queue<unsigned int,vector<unsigned int>,greater<unsigned int> > q;

    unsigned seed = (unsigned int) std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(5,100);

    for (int i = 0; i < size; i++) {
        unsigned int value = (unsigned int) distribution(generator);
        value += distribution(generator);

        v[i] = value;
        q.push(value);
    }
    cout << endl;

    Heap* h = new Heap();

    h->buildHeap(v, size);

    while (!q.empty()) {
        unsigned int min = h->heapExtractMin();
        unsigned int expectedMin = q.top();
        q.pop();


        if (expectedMin != min) {
            cout << "Expected: " << expectedMin << endl;
            cout << "Actual: " << min << endl;
        }
    }

    return 0;
}