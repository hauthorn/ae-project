#include <iostream>
#include <ctime>
#include <fstream>
#include "LinearScanPred.cpp"
#include "BinarySearchRec.cpp"
#include "BinarySearchIte.cpp"
#include "BinaryTreePred.cpp"
#include "BinarySearchBFS.cpp"
#include "papi.h"
#include "fileutils/FileUtils.h"
#include <chrono>

#define NUM_EVENTS 1

using namespace std;
using namespace std::chrono;

const int N = 900;
unsigned int MAX = 10000;
vector<unsigned int> X;

int main(int argc, char *argv[]) {

    int events[NUM_EVENTS];
    long_long values[NUM_EVENTS];

    string papi_label;
    bool papi_enabled = false;

    int ret;

    milliseconds ms = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
    );

    string fileName = to_string(ms.count());



    // Initialize based on command line, use linearscanpred as default for now
    BasePred *pred = new LinearScanPred();
    string algoName = "lin";
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
                algoName = "binrec";
            } else if (string(argv[i + 1]) == "binaryIterative") {
                cout << "Using binary search algorithm iterative" << endl;
                pred = new BinarySearchIte();
                algoName = "binite";
            } else if (string(argv[i + 1]) == "binaryTree") {
                cout << "Using binary search tree algorithm" << endl;
                pred = new BinaryTreePred();
                algoName = "bintree";
            }
            else if (string(argv[i + 1]) == "binaryBFS") {
                cout << "Using binary search BFS algorithm" << endl;
                pred = new BinarySearchBFS();
                algoName = "binbfs";
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
            } else if (string(argv[i + 1]) == "l1_dcm") {
                cout << "Measuring L1 Data cache misses" << endl;
                events[0] = PAPI_L1_DCM;
            } else if (string(argv[i + 1]) == "l2_dcm") {
                cout << "Measuring L2 Data cache misses" << endl;
                events[0] = PAPI_L2_DCM;
            } else if(string(argv[i+1]) == "l3_dcm") {
                cout << "Measuring L3 Data cache misses" << endl;
                events[0] = PAPI_L3_DCM;
            } else if (string(argv[i+1]) == "l1_tcm") {
                // (tcm) total cache misses
                events[0] = PAPI_L1_TCM;
            } else if (string(argv[i+1]) == "l2_tcm") {
                events[0] = PAPI_L2_TCM;
            } else if(string(argv[i+1]) == "l3_tcm"){
                events[0] = PAPI_L3_TCM;
            } else if(string(argv[i+1]) == "tot_iis") {
                // instructions issued
                events[0] = PAPI_TOT_IIS;
            } else if(string(argv[i+1]) == "tlb_tl") {
                // total tlb misses
                events[0] = PAPI_TLB_TL;
            } else if(string(argv[i+1]) == "tlb_im") {
                // tlb ins
                events[0] = PAPI_TLB_IM;
            } else if(string(argv[i+1]) == "csr_tot") {
                // total store conditional instructions
                events[0] = PAPI_CSR_TOT;
            } else if(string(argv[i+1]) == "br_cn") {
                events[0] = PAPI_BR_CN;
            } else {
                papi_enabled = false;
            }
        } else if (string(argv[i]) == "-f") {
            fileName = string(argv[i+1]);
        } else if (string(argv[i]) == "-max") {
            MAX = atol(argv[i+1]);
        }


    }
    std::ofstream outfile;


    if (papi_enabled && PAPI_num_counters() < NUM_EVENTS) {
        fprintf(stderr, "No hardware counters here, or PAPI not supported.\n");
    }
    if (papi_enabled && (ret = PAPI_start_counters(events, NUM_EVENTS)) != PAPI_OK) {
        fprintf(stderr, "PAPI failed to start counters: %s\n", PAPI_strerror(ret));
    }

    string command =  "mkdir -p " + fileName;
    system(command.c_str());


    for (unsigned int j = 1024; j <= MAX; j = j+j) {
        // Build an array of integers of size X
        unsigned int tmp = 0;
        X = vector<unsigned int>();

        for (unsigned int i = 0; i < (j - 1); ++i) {
            X.push_back(tmp + i);
            tmp = tmp + 10;
        }

        cout << "Array size: " << j - 1 << endl;

        // Set the array
        pred->setArray(X);
        int thePred = 0;

        if (papi_enabled && (ret = PAPI_read_counters(values, NUM_EVENTS)) != PAPI_OK) {
            fprintf(stderr, "PAPI failed to start counters: %s\n", PAPI_strerror(ret));
        }

        long_long cpuRead = 0;

        // Start timer
        clock_t begin = clock();

        // Run algorithm numberOfRuns times
        for (unsigned int runs = 1; runs <= numberOfRuns; runs++) {

            if (papi_enabled && (ret = PAPI_read_counters(values, NUM_EVENTS)) != PAPI_OK) {
                fprintf(stderr, "PAPI failed to read counters: %s\n", PAPI_strerror(ret));
            }

            // IT14 was run using this: unsigned int testPred = tmp / numberOfRuns;
            unsigned int testPred = rand() % tmp;
            thePred = pred->pred(testPred);
            cpuRead += values[0];
        }


        // End timer
        clock_t end = clock();

        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        double average_secs = elapsed_secs / numberOfRuns;
        cpuRead = cpuRead / numberOfRuns;
        if(papi_enabled)
            cout << papi_label << ": " << cpuRead << endl;

        cout << endl;

        // Output to tsv file
        outfile.open(FileUtils::getRuntimeFileName(fileName, algoName), std::ios_base::app);
        outfile << j << "\t" << average_secs << endl;
        outfile.close();



        // write papi results to file
        if(papi_enabled) {
            outfile.open(FileUtils::getPapiFileName(papi_label, fileName, algoName), std::ios_base::app);
            outfile << j << "\t" << cpuRead << endl;
            outfile.close();
        }
    }

    // Print the plot
    string call = string(
            "gnuplot -e \"set term png;set output '" + FileUtils::getOutputName(fileName, algoName) +"'; plot '" + FileUtils::getRuntimeFileName(fileName, algoName) +"' with points\"");
    system(call.c_str());

    if(papi_enabled) {
        // Print the plot
        call = string(
                "gnuplot -e \"set term png;set output '" + FileUtils::getOutputName(papi_label, fileName, algoName) + "'; plot '" + FileUtils::getPapiFileName(papi_label, fileName, algoName) + "' with points\"");
        system(call.c_str());
    }


    return 0;
}