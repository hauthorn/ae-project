#include <iostream>
#include <ctime>
#include <fstream>
#include "LinearScanPred.cpp"
#include "BinarySearch.cpp"
#include "papi.h"

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
    int numberOfRuns = 1;

    for(int i = 1; i <= argc; i+=2) {
        if(i+1 >= argc)
            break;

        if(string(argv[i]) == "a") {
            if (string(argv[i+1]) == "linear") {
                cout << "Using linear algorithm" << endl;
                pred = new LinearScanPred();
            }
            else if (string(argv[i+1]) == "binary") {
                cout << "Using binary search algorithm" << endl;
                pred = new BinarySearch();
            }
        } else if (string(argv[i]) == "n") {
            numberOfRuns = atoi(argv[i+1]);
            cout << "Number of runs: " << numberOfRuns << endl;
        } else if(string(argv[i]) == "m") {
            if(string(argv[i+1]) == "br_msp") {
                cout << "Measuring branch mispredictions" << endl;
                events[0] = PAPI_BR_MSP;
            } else if(string(argv[i+1]) == "l2_dcm") {
                cout << "Measuring L2 Data cache misses" << endl;
                events[0] = PAPI_L2_DCM;
            }
        }


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

        long_long cpuRead;

        // Run algorithm numberOfRuns times
        for (int runs = 1; runs <= numberOfRuns; runs++) {

            if ((ret = PAPI_read_counters(values, NUM_EVENTS)) != PAPI_OK) {
                fprintf(stderr, "PAPI failed to read counters: %s\n", PAPI_strerror(ret));
                exit(1);
            }

            int testPred = tmp / runs;
            thePred = pred->pred(testPred);

            cpuRead += values[0];
        }


        // End timer
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        double average_secs = elapsed_secs / numberOfRuns;
        cpuRead = cpuRead / numberOfRuns;
        cout << "Pred: " << thePred << " cpuRead " << cpuRead <<endl;

        // Output to tsv file
        outfile.open("test.txt", std::ios_base::app);
        outfile << j << "\t" << average_secs << endl;
        outfile.close();
    }



    // Print the plot
    system("gnuplot -e \"set term png;set output 'test.png'; plot 'test.txt' with lines\"");

    return 0;
}
