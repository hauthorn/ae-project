#!/usr/bin/env bash
cd ..;
cmake --build . --target matrixMultiply -- -j 2;

# This fits in main memory of Anders' server
./matrixRecursive -n 5 -max 2048 -m l1_dcm -f $1;
./matrixRecursive -n 5 -max 2048 -m l2_dcm -f $1;
./matrixRecursive -n 5 -max 2048 -m tot_iis -f $1;

./matrixMultiply -a simple -n 5 -max 2200 -m l1_dcm -f $1;
./matrixMultiply -a simple -n 5 -max 2200 -m l2_dcm -f $1;

./matrixMultiply -a simpleTranspose -n 5 -max 2200 -m l1_dcm -f $1
./matrixMultiply -a simpleTranspose -n 5 -max 2200 -m l2_dcm -f $1


./matrixMultiply -a 1dTranspose -n 5 -max 2200 -m l1_dcm -f $1
./matrixMultiply -a 1dTranspose -n 5 -max 2200 -m l2_dcm -f $1

./matrixMultiply -a 1d -n 5 -max 2200 -m l1_dcm -f $1
./matrixMultiply -a 1d -n 5 -max 2200 -m l2_dcm -f $1

./matrixMultiply -a matrixTile -n 5 -max 2200 -m l1_dcm -f $1
./matrixMultiply -a matrixTile -n 5 -max 2200 -m l2_dcm -f $1
./matrixMultiply -a matrixTile -n 5 -max 2200 -m tot_iis -f $1
