//
// This tests our algorithms by comparing their results to each other
//

#include <iostream>
#include <vector>

#include "LinearScanPred.cpp"
#include "BinarySearchRec.cpp"
#include "BinarySearchIte.cpp"
#include "BinaryTreePred.cpp"

using namespace std;

const int N = 1000000;
vector<unsigned int> X(N);
const int NUM_TESTS = 1000;

int main(int argc, char *argv[]) {
    cout << "Verifying algorithms" << endl;

    // Build an array of integers of size N
    unsigned int tmp = 0;

    for (unsigned int i = 0; i < N; ++i) {
        X[i] = tmp + i;
        tmp = tmp + 10;
    }

    cout << "Initialize the algorithms" << endl;
    vector<BasePred*> algorithms(4);
    algorithms[0] = new LinearScanPred();
    algorithms[1] = new BinarySearchIte();
    algorithms[2] = new BinarySearchRec();
    algorithms[3] = new BinaryTreePred();

    cout << "Setting arrays" << endl;

    for (int j = 0; j < algorithms.size(); ++j) {
        algorithms[j]->setArray(X);
    }

    cout << "Running tests" << endl;

    // Run some Pred queries
    for (int k = 0; k < NUM_TESTS; ++k) {
        // The value to search for
        unsigned int search = rand() % tmp + 1; // between 1 and tmp
        unsigned int previousResult = 0;

        for (int i = 0; i < algorithms.size(); ++i) {
            unsigned int result = algorithms[i]->pred(search);
            if (previousResult == 0) {
                previousResult = result;
            }
            
            if (previousResult != result) {
                fprintf(stderr, "Results differ between algorithms!\n");
            }
            
            previousResult = result;
        }
    }

    return 0;
}
