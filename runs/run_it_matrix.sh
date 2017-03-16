#!/usr/bin/env bash
cd ..;
cmake --build . --target matrixMultiply -- -j 2;

# This fits in main memory of Anders' server

./matrixMultiply -a simple -n 5 -max 2000 -m l1_dcm -f $1;
./matrixMultiply -a simple -n 5 -max 2000 -m l2_dcm -f $1;

./matrixMultiply -a simpleTranspose -n 5 -max 2000 -m l1_dcm -f $1
./matrixMultiply -a simpleTranspose -n 5 -max 2000 -m l2_dcm -f $1

./matrixMultiply -a 1dTranspose -n 5 -max 2000 -m l1_dcm -f $1
./matrixMultiply -a 1dTranspose -n 5 -max 2000 -m l2_dcm -f $1

./matrixMultiply -a 1d -n 5 -max 2000 -m l1_dcm -f $1
./matrixMultiply -a 1d -n 5 -max 2000 -m l2_dcm -f $1

./matrixMultiply -a matrixTile -n 5 -max 2000 -m l1_dcm -f $1
./matrixMultiply -a matrixTile -n 5 -max 2000 -m l2_dcm -f $1
