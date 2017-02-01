#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

const int N=10000;
const int MAX=15000;

int main() {
    std::ofstream outfile;

    outfile.open("test.txt", std::ios_base::app);

    for (int j = N; j < MAX; j = j + 1000) {
        // Build an array of integers of size X
        int tmp = 0, X[j];

        for (int i = 0; i < j; ++i) {
            X[i] = tmp + i;
            tmp = tmp + 1;
        }

        // Start timer
        clock_t begin = clock();

        // Run algorithm


        // End timer
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

        // Output to tsv file
        outfile << N << "\t" << elapsed_secs << endl;
    }

    // Cleanup
    outfile.close();
    return 0;
}
