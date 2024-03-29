#include <iostream>
#include "unfolded/Binaryheap.cpp"
#include <ctime>
#include <fstream>
#include "papi.h"
#include "../fileutils/FileUtils.h"
#include <chrono>
#include "KaryHeap.cpp"
#include "QueueHeap.cpp"
#include "unfolded/TernaryHeap.cpp"
#include "unfolded/QuadHeap.cpp"
#include "unfolded/SevenHeap.cpp"
#include "unfolded/EightHeap.cpp"
#include "unfolded/NineHeap.cpp"
#include "unfolded/TenHeap.cpp"
#include "unfolded/ElevenHeap.cpp"

#define NUM_EVENTS 1

using namespace std;
using namespace std::chrono;

unsigned int MAX = 100000;
unsigned int* X;

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

    // Initialize based on command line, use binary heap as default for now
    BaseHeap *heap = new BinaryHeap();
    string algoName = "binaryHeap";
    int numberOfRuns = 1;

    string measure_label;

    for (int i = 1; i <= argc; i += 2) {
        if (i + 1 >= argc)
            break;

        if (string(argv[i]) == "-a") {
            if (string(argv[i + 1]) == "binaryheap") {
                cout << "Using binary heap algorithm" << endl;
                heap = new BinaryHeap();
            } else if (string(argv[i + 1]) == "3heap") {
                cout << "Using 3-ary heap" << endl;
                heap = new KaryHeap(3);
                algoName = "3heap";
            } else if (string(argv[i + 1]) == "4heap") {
                cout << "Using 4-ary heap" << endl;
                heap = new KaryHeap(4);
                algoName = "4heap";
            } else if (string(argv[i + 1]) == "7heap") {
                cout << "Using 7-ary heap" << endl;
                heap = new KaryHeap(7);
                algoName = "7heap";
            }
            else if (string(argv[i + 1]) == "queueheap") {
                cout << "Using queue heap" << endl;
                heap = new QueueHeap();
                algoName = "queueheap";
            }
            else if (string(argv[i + 1]) == "ternaryheap") {
                cout << "Using ternary heap" << endl;
                heap = new TernaryHeap();
                algoName = "ternaryheap";
            }
            else if (string(argv[i + 1]) == "quadheap") {
                cout << "Using quad heap" << endl;
                heap = new QuadHeap();
                algoName = "quadheap";
            }
            else if (string(argv[i + 1]) == "sevenheap") {
                cout << "Using seven heap" << endl;
                heap = new SevenHeap();
                algoName = "sevenheap";
            }
            else if (string(argv[i + 1]) == "eightheap") {
                cout << "Using eight heap" << endl;
                heap = new EightHeap();
                algoName = "eightheap";
            }
            else if (string(argv[i + 1]) == "nineheap") {
                cout << "Using nine heap" << endl;
                heap = new NineHeap();
                algoName = "nineheap";
            }
            else if (string(argv[i + 1]) == "tenheap") {
                cout << "Using ten heap" << endl;
                heap = new TenHeap();
                algoName = "tenheap";
            }
            else if (string(argv[i + 1]) == "elevenheap") {
                cout << "Using eleven heap" << endl;
                heap = new ElevenHeap();
                algoName = "elevenheap";
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
        // Build an array of integers of size j
        unsigned int tmp = 0;
        X = new unsigned int[j];

        for (unsigned int i = 0; i < j; ++i) {
            X[i] = tmp + i;
            tmp = tmp + 10;
        }

        cout << "Array size: " << j << endl;

        // Set the array
        heap->buildHeap(X, j);
        int theMin = 0;

        if (papi_enabled && (ret = PAPI_read_counters(values, NUM_EVENTS)) != PAPI_OK) {
            fprintf(stderr, "PAPI failed to start counters: %s\n", PAPI_strerror(ret));
        }

        long_long cpuRead = 0;

        // Start timer
        typedef std::chrono::high_resolution_clock Clock;
        auto begin = Clock::now();

        // Run algorithm numberOfRuns times
        for (unsigned int runs = 1; runs <= numberOfRuns; runs++) {

            if (papi_enabled && (ret = PAPI_read_counters(values, NUM_EVENTS)) != PAPI_OK) {
                fprintf(stderr, "PAPI failed to read counters: %s\n", PAPI_strerror(ret));
            }

            // Do j / 2 extracts
            for (int i = 0; i < j / 2; ++i) {
                theMin = heap->heapExtractMin();
            }

            // Do j / 2 inserts
            for (int i = 0; i < j / 2; ++i) {
                heap->insert(rand() % tmp + 1); // Insert values less than the known max
            }

            cpuRead += values[0];
        }

        // End timer
        auto end = Clock::now();

        double elapsed_secs = (end - begin).count();
        double average_secs = elapsed_secs / numberOfRuns;
        cpuRead = cpuRead / numberOfRuns;
        if(papi_enabled)
            cout << papi_label << ": " << cpuRead << endl;

        cout << endl;

        cout << "Last min: " << theMin << endl;

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

        delete X;
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