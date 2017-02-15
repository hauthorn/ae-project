#include <iostream>
#include <ctime>
#include <fstream>
#include "LinearScanPred.cpp"
#include "BinarySearchRec.cpp"
#include "BinarySearchIte.cpp"
#include "papi.h"
#include <chrono>

#define NUM_EVENTS 1

using namespace std;
using namespace std::chrono;

const int N = 1000;
const long MAX = 100000000;


int main(int argc, char *argv[]) {

    int events[NUM_EVENTS];
    long_long values[NUM_EVENTS];

    string papi_label;
    bool papi_enabled = false;

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

    string measure_label;

    for (int i = 1; i <= argc; i += 2) {
        if (i + 1 >= argc)
            break;

        if (string(argv[i]) == "-a") {
            if (string(argv[i + 1]) == "linear") {
                cout << "Using linear algorithm" << endl;
                pred = new LinearScanPred();
            } else if (string(argv[i + 1]) == "binaryRecursive") {
                cout << "Using binary search algorithm recursive" << endl;
                pred = new BinarySearchRec();
            } else if (string(argv[i+1]) == "binaryIterative") {
                cout << "Using binary search algorithm iterative" << endl;
                pred = new BinarySearchIte();
            }
        } else if (string(argv[i]) == "-n") {
            numberOfRuns = atoi(argv[i + 1]);
            cout << "Number of runs: " << numberOfRuns << endl;
        } else if (string(argv[i]) == "-m") {
            papi_enabled = true;
            papi_label = string(argv[i+1]);

            // choose what to measure
            if (string(argv[i + 1]) == "br_msp") {
                cout << "Measuring branch mispredictions" << endl;
                events[0] = PAPI_BR_MSP;
            } else if (string(argv[i + 1]) == "l2_dcm") {
                cout << "Measuring L2 Data cache misses" << endl;
                events[0] = PAPI_L2_DCM;
            } else {
                papi_enabled = false;
            }
        }


    }
    std::ofstream outfile;


    if (papi_enabled && (ret = PAPI_start_counters(events, NUM_EVENTS)) != PAPI_OK) {
        fprintf(stderr, "PAPI failed to start counters: %s\n", PAPI_strerror(ret));
    }


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

        // Start timer
        clock_t begin = clock();

        if (papi_enabled && (ret = PAPI_read_counters(values, NUM_EVENTS)) != PAPI_OK) {
            fprintf(stderr, "PAPI failed to start counters: %s\n", PAPI_strerror(ret));
        }

        long_long cpuRead = 0;

        // Run algorithm numberOfRuns times
        for (int runs = 1; runs <= numberOfRuns; runs++) {

            if (papi_enabled && (ret = PAPI_read_counters(values, NUM_EVENTS)) != PAPI_OK) {
                fprintf(stderr, "PAPI failed to read counters: %s\n", PAPI_strerror(ret));
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
        cout << "Pred: " << thePred << " ";
        if(papi_enabled)
            cout << papi_label << ": " << cpuRead << endl;

        cout << endl;

        // Output to tsv file
        outfile.open(timestamp + ".txt", std::ios_base::app);
        outfile << j << "\t" << average_secs << endl;
        outfile.close();

        // write papi results to file
        if(papi_enabled) {
            outfile.open(timestamp + "_" + papi_label + ".txt", std::ios_base::app);
            outfile << j << "\t" << cpuRead << endl;
            outfile.close();
        }
    }

    // Print the plot
    string call = string(
            "gnuplot -e \"set term png;set output '" + timestamp + ".png'; plot '" + timestamp + ".txt' with lines\"");
    system(call.c_str());

    return 0;
}
