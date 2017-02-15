#include <iostream>
#include <ctime>
#include <fstream>
#include "LinearScanPred.cpp"
#include "BinarySearch.cpp"
#include "papi.h"
#include <chrono>

#define NUM_EVENTS 2

// define how many different test sets
#define NUM_PAPI_TEST_SETS 2
using namespace std;
using namespace std::chrono;

const int N = 1000;
const long MAX = 100000000;


int main(int argc, char *argv[]) {
    int ret;

    milliseconds ms = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
    );

    string timestamp = to_string(ms.count());

    if (PAPI_num_counters() < NUM_EVENTS) {
        fprintf(stderr, "No hardware counters here, or PAPI not supported.\n");
    }


    // Initialize based on command line, use linearscanpred as default for now
    BasePred *pred = new LinearScanPred();
    int numberOfRuns = 1;

    for (int i = 1; i <= argc; i += 2) {
        if (i + 1 >= argc)
            break;

        if (string(argv[i]) == "a") {
            if (string(argv[i + 1]) == "linear") {
                cout << "Using linear algorithm" << endl;
                pred = new LinearScanPred();
            } else if (string(argv[i + 1]) == "binary") {
                cout << "Using binary search algorithm" << endl;
                pred = new BinarySearch();
            }
        } else if (string(argv[i]) == "n") {
            numberOfRuns = atoi(argv[i + 1]);
            cout << "Number of runs: " << numberOfRuns << endl;
        }/* else if (string(argv[i]) == "m") {
            if (string(argv[i + 1]) == "br_msp") {
                cout << "Measuring branch mispredictions" << endl;
                events[0] = PAPI_BR_MSP;
            } else if (string(argv[i + 1]) == "l2_dcm") {
                cout << "Measuring L2 Data cache misses" << endl;
                events[0] = PAPI_L2_DCM;
            }
        }*/


    }
    std::ofstream outfile;




    for (int j = N; j <= MAX; j = j + j) {
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

        double elapsed_secs = 0;

        int events[NUM_PAPI_TEST_SETS][NUM_EVENTS] = {{PAPI_BR_MSP, PAPI_L2_TCM},{PAPI_BR_CN,PAPI_BR_MSP}};
        long_long values[NUM_EVENTS];
        int events_length[NUM_PAPI_TEST_SETS] = {2,2};
        long_long storedValues[NUM_PAPI_TEST_SETS * NUM_EVENTS];

        // foreach dataset we need to run different reads using papi, which cannot be done simultaneously
        for(int i = 0; i < NUM_PAPI_TEST_SETS; i++) {

            if ((ret = PAPI_start_counters(events[i], events_length[i])) != PAPI_OK) {
                fprintf(stderr, "PAPI failed to start counters: %s\n", PAPI_strerror(ret));
            }

            // Start timer
            clock_t begin = clock();

            // reset counters
            if ((ret = PAPI_read_counters(values, events_length[i])) != PAPI_OK) {
                fprintf(stderr, "PAPI failed to start counters: %s\n", PAPI_strerror(ret));
            }


            // Run algorithm numberOfRuns times
            for (int runs = 1; runs <= numberOfRuns; runs++) {
                int testPred = tmp / runs;
                thePred = pred->pred(testPred);
            }

            // read counters afterwards
            if ((ret = PAPI_read_counters(values, events_length[i])) != PAPI_OK) {
                fprintf(stderr, "PAPI failed to read counters: %s\n", PAPI_strerror(ret));
            }

            // store mean values
            for(int j = 0; j < events_length[i];j++) {
                storedValues[(i*events_length[i]) + j] = values[j] / numberOfRuns;
            }

            elapsed_secs+= double(clock()-begin);

            // stop counters
            PAPI_stop_counters(values, events_length[i]);
        }

        // End timer
        clock_t end = clock();
        // double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        double average_secs = elapsed_secs / numberOfRuns*NUM_PAPI_TEST_SETS;
        cout << "Pred: " << thePred;

        for(int i = 0; i < NUM_PAPI_TEST_SETS; i++) {
            for(int j = 0; j < events_length[i]; j++) {
                cout << " " << storedValues[i*events_length[i]+j];
            }
        }

        cout << endl;

        // Output to tsv file
        outfile.open(timestamp + ".txt", std::ios_base::app);
        outfile << j << "\t" << average_secs << endl;
        outfile.close();
    }

    // Print the plot
    string call = string(
            "gnuplot -e \"set term png;set output '" + timestamp + ".png'; plot '" + timestamp + ".txt' with lines\"");
    system(call.c_str());

    return 0;
}
