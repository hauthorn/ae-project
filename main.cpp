#include <iostream>
#include <ctime>
#include <fstream>
#include "LinearScanPred.cpp"
#include "BinarySearch.cpp"
#include "papi.h"
#include <stdlib.h>
#include <memory.h>

#define NUM_EVENTS 1
using namespace std;

const int N=10000000;
const int MAX=10100000;



int main(int argc, char* argv[]) {
    int events[NUM_EVENTS] = {PAPI_BR_MSP};
    long_long values[NUM_EVENTS];
    int ret;


    if (PAPI_num_counters() < NUM_EVENTS) {
        fprintf(stderr, "No hardware counters here, or PAPI not supported.\n");
        exit(1);
    }


    // Initialize based on command line, use linearscanpred as default for now
    BasePred *pred = new LinearScanPred();
    if (argc > 1) {
        if (string(argv[1]) == "linear") {
            cout << "Using linear algorithm" << endl;
            pred = new LinearScanPred();
        }
        else if (string(argv[1]) == "binary") {
            cout << "Using binary search algorithm" << endl;
            pred = new BinarySearch();
        }
    }

    // How many times should we run pred per array?
    int numberOfRuns = 1;
    if (argc > 2) {
        numberOfRuns = atoi(argv[2]);
        cout << "Number of runs: " << numberOfRuns << endl;
    }

    std::ofstream outfile;


    if ((ret = PAPI_start_counters(events, NUM_EVENTS)) != PAPI_OK) {
        fprintf(stderr, "PAPI failed to start counters: %s\n", PAPI_strerror(ret));
        exit(1);
    }


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
        int thePred = 0;

        // Start timer
        clock_t begin = clock();

        if ((ret = PAPI_read_counters(values, NUM_EVENTS)) != PAPI_OK) {
            fprintf(stderr, "PAPI failed to start counters: %s\n", PAPI_strerror(ret));
            exit(1);
        }

        // Run algorithm numberOfRuns times
        for (int runs = 1; runs <= numberOfRuns; runs++) {

            if ((ret = PAPI_read_counters(values, NUM_EVENTS)) != PAPI_OK) {
                fprintf(stderr, "PAPI failed to read counters: %s\n", PAPI_strerror(ret));
                exit(1);
            }

            int testPred = tmp / runs;
            thePred = pred->pred(testPred);


            printf("Branch mispredictions: %lld\n", values[0]);
        }


        // End timer
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        double average_secs = elapsed_secs / numberOfRuns;
        cout << "Pred: " << thePred << endl;

        // Output to tsv file
        outfile.open("test.txt", std::ios_base::app);
        outfile << j << "\t" << average_secs << endl;
        outfile.close();
    }



    // Print the plot
    system("gnuplot -e \"set term png;set output 'test.png'; plot 'test.txt' with lines\"");

    return 0;
}
