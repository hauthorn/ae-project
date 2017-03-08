//
// Created by frederik on 3/8/17.
//

#include <vector>
#include <iostream>
#include "heap.cpp"


using namespace std;

int main() {

    vector<unsigned int> v = {9,16,2,5,1,2,4,8,3,6};

    Heap* h = new Heap();

    h->buildHeap(v);



    unsigned int min = h->heapExtractMin();
    cout << min << endl;

    return 0;
}