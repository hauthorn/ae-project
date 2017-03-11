#include <iostream>
#include "matrix.cpp"
#include <ctime>
#include <fstream>
#include "papi.h"
#include "../fileutils/FileUtils.h"
#include <chrono>

#define NUM_EVENTS 1

using namespace std;
using namespace std::chrono;

const int N = 900;
unsigned int MAX = 10000;

int main(int argc, char *argv[]) {
    int events[NUM_EVENTS];
    long_long values[NUM_EVENTS];

    string papi_label;
    bool papi_enabled = true;

    int ret;

    milliseconds ms = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
    );

    string fileName = to_string(ms.count());


    // simple
    string algoName = "simple";

    int numberOfRuns = 1;

    string measure_label;

    int dimension = 2;

    for (int i = 1; i <= argc; i += 2) {
        if (i + 1 >= argc)
            break;

        if (string(argv[i]) == "-n") {
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
        } else if(string(argv[i]) == "-a") {
            if(string(argv[i+1]) == "simpleTranspose") {
                algoName = "simpleTranspose";
            } else if(string(argv[i+1]) == "1d") {
                algoName = "1d";
                dimension = 1;
            } else if(string(argv[i+1]) == "1dTranspose") {
                algoName = "1dTranspose";
                dimension = 1;
            }
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


    for (unsigned int j = MAX; j > 1; j = j/2) {
        int **a;
        int **b;



        int *a1;

        a1 = new int[j*j];
        int *b1;

        b1 = new int[j*j];


        if(j <= 2)
            break;

        // fill matrices with random numbers
        cout << "Array size: " << j << endl;
        cout << "Algorithm: " << algoName << " dimension " << dimension << endl;

        if (papi_enabled && (ret = PAPI_read_counters(values, NUM_EVENTS)) != PAPI_OK) {
            fprintf(stderr, "PAPI failed to start counters: %s\n", PAPI_strerror(ret));
        }

        long_long cpuRead = 0;

        int rank;

        a = new int *[j];
        b = new int *[j];

        double elapsed_secs = 0;

        // Run algorithm numberOfRuns times
        for (unsigned int runs = 1; runs <= numberOfRuns; runs++) {

            // fill array with random numbers (we don't want to measure this)
            for(int i = 0; i < j; i++) {
                if(dimension == 2)
                    a[i] = new int[j];

                for(int k = 0; k < j; k++) {
                    if(dimension == 1)
                        a1[j*i+k] = rand()%MAX;
                    else
                        a[i][k] = rand()%MAX;
                }
            }

            for(int i = 0; i <j; i++) {
                if(dimension == 2)
                    b[i] = new int[j];

                for(int k = 0; k < j; k++) {
                    if(dimension == 1)
                        b1[j*i+k] = rand()%MAX;
                    else
                        b[i][k] = rand()%MAX;
                }
            }



            // empty papi counters before measuring multiply
            if (papi_enabled && (ret = PAPI_read_counters(values, NUM_EVENTS)) != PAPI_OK) {
                fprintf(stderr, "PAPI failed to read counters: %s\n", PAPI_strerror(ret));
            }


            // Start timer
            clock_t begin = clock();

            int **c;
            int *c1;

            if(algoName == "simpleTranspose") {
                c = matrixMultiplySimpleTranspose(a,b,j);
            } else if(algoName == "1d") {
                c1 = matrixOneDimension(a1,b1,j);
            } else if(algoName == "1dTranspose") {
                c1 = matrixOneDimensionTranspose(a1,b1,j);
            } else {
                // simple
                c = matrixMultiplySimple(a,b,j);
            }


            if (papi_enabled && (ret = PAPI_read_counters(values, NUM_EVENTS)) != PAPI_OK) {
                fprintf(stderr, "PAPI failed to read counters: %s\n", PAPI_strerror(ret));
            }

            elapsed_secs += double(clock() - begin) / CLOCKS_PER_SEC;
            cpuRead += values[0];

            if(dimension == 1)
                rank = c1[1];
            else
                rank = c[1][1];
        }

        double average_secs = elapsed_secs / numberOfRuns;
        cpuRead = cpuRead / numberOfRuns;
        if(papi_enabled)
            cout << papi_label << ": " << cpuRead << endl;

        cout << "out" << rank;// just to make sure it is not skipped by the compiler
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