#include <iostream>
#include <ctime>
#include <fstream>
#include "Pred.cpp"
#include "LinearScanPred.cpp"
#include "papi.h"
#include <stdlib.h>
#include <memory.h>


using namespace std;

const int N=10000000;
const int MAX=10100000;

extern int PAPI_flops( float *rtime, float *ptime, long long *flpops, float *mflops );

int main(int argc, char* argv[]) {
    long long flpins;

    float real_time, proc_time, mflops;
    int retval;

    /* Setup PAPI library and begin collecting data from the counters */
    if((retval = PAPI_flops( &real_time, &proc_time, &flpins, &mflops))<PAPI_OK) {
        cout << "ERROR";
    }

    // Initialize based on command line, use linearscanpred as default for now
    BasePred *pred = new LinearScanPred();
    if (argc > 1) {
        if (string(argv[1]) == "linear") {
            cout << "Using linear algorithm" << endl;
            pred = new LinearScanPred();
        }
    }

    std::ofstream outfile;


    for (int j = N; j <= MAX; j = j + 10000) {
        // Build an array of integers of size X
        int tmp = 0;
        vector<int> X(j);

        for (int i = 0; i < j; ++i) {
            X[i] = tmp + i;
            tmp = tmp + 10;
        }

        // Set the array
        pred->setArray(X);

        // Start timer
        clock_t begin = clock();

        // Run algorithm
        int thePred = pred->pred(89);

        // End timer
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

        cout << "Pred: " << thePred << endl;

        // Output to tsv file
        outfile.open("test.txt", std::ios_base::app);
        outfile << j << "\t" << elapsed_secs << endl;
        outfile.close();
    }


    if((retval=PAPI_flops( &real_time, &proc_time, &flpins, &mflops))<PAPI_OK) {
        cout << "error";
    }

    printf("Real_time:\t%f\nProc_time:\t%f\nTotal flpins:\t%lld\nMFLOPS:\t\t%f\n",real_time, proc_time, flpins, mflops);
    printf("%s\tPASSED\n", __FILE__);
    PAPI_shutdown();


    // Print the plot
    system("gnuplot -e \"set term png;set output 'test.png'; plot 'test.txt' with lines\"");

    return 0;
}
