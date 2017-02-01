#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "Pred.cpp"

using namespace std;

const int N=10000000;
const int MAX=10100000;

int main() {
    std::ofstream outfile;



    for (int j = N; j <= MAX; j = j + 10000) {
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

        // End timer
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

        cout << "Pred: " << pred << endl;

        // Output to tsv file
        outfile.open("test.txt", std::ios_base::app);
        outfile << j << "\t" << elapsed_secs << endl;
        outfile.close();
    }

    // Print the plot
    system("gnuplot -e \"set term png;set output 'test.png'; plot 'test.txt' with lines\"");

    return 0;
}
