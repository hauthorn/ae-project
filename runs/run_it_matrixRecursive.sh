#!/usr/bin/env bash
cd ..;
cmake --build . --target matrixRecursive -- -j 2;

# This fits in main memory of Anders' server
#./matrixRecursive -n 20 -max 2048 -m l1_dcm -f $1;
#./matrixRecursive -n 20 -max 2048 -m l2_dcm -f $1;
