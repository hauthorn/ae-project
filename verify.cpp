//
// This tests our algorithms by comparing their results to eachother
//

#include <iostream>
#include <vector>

#include "LinearScanPred.cpp"
#include "BinarySearchRec.cpp"
#include "BinarySearchIte.cpp"

using namespace std;

const int N = 1000;

const int NUM_TESTS = 100;

int main(int argc, char *argv[]) {
    cout << "Verifying algorithms" << endl;

    // Build an array of integers of size N
    int tmp = 0;
    vector<int> X(N);

    for (int i = 0; i < N; ++i) {
        X[i] = tmp + i;
        tmp = tmp + 10;
    }

    // Initialize the algorithms
    vector<BasePred*> algoritms(3);
    algoritms[0] = new LinearScanPred();
    algoritms[1] = new BinarySearchIte();
    algoritms[2] = new BinarySearchRec();

    for (int j = 0; j < algoritms.size(); ++j) {
        algoritms[j]->setArray(X);
    }

    // Run some Pred queries
    for (int k = 0; k < NUM_TESTS; ++k) {
        // The value to search for
        int search = rand() % tmp + 1; // between 1 and tmp
        int previousResult = 0;

        for (int i = 0; i < algoritms.size(); ++i) {
            int result = algoritms[i]->pred(search);
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
