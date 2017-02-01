#include <iostream>
#include <ctime>
#include <fstream>
#include "Pred.cpp"

using namespace std;

const int N=10000;
const int MAX=10000;

int main() {
    std::ofstream outfile;

    outfile.open("test.txt", std::ios_base::app);

    for (int j = N; j <= MAX; j = j + 1000) {
        // Build an array of integers of size X
        int tmp = 0;
        vector<int> X(j);

        for (int i = 0; i < j; ++i) {
            X[i] = tmp + i;
            tmp = tmp + 10;
        }

        // Start timer
        clock_t begin = clock();

        // Run algorithm
        int pred = Pred::predWithScan(X, 89);
        
        cout << "Pred: " << pred << endl;

        // End timer
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

        // Output to tsv file
        outfile << j << "\t" << elapsed_secs << endl;
    }

    // Cleanup
    outfile.close();
    return 0;
}
