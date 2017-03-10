#!/usr/bin/env bash
cd ..;
cmake --build . --target rankSelect -- -j 2;

# This fits in main memory of Anders' server
./matrixMultiply -a simple -n 100 -max 512 -m br_msp -f $1;
./matrixMultiply -a simple -n 100 -max 512 -m br_cn -f $1;
./matrixMultiply -a simple -n 100 -max 512 -m l1_dcm -f $1;
./matrixMultiply -a simple -n 100 -max 512 -m l2_dcm -f $1;

./matrixMultiply -a simpleTranspose -n 100 -max 512 -m br_msp -f $1
./matrixMultiply -a simpleTranspose -n 100 -max 512 -m br_cn -f $1
./matrixMultiply -a simpleTranspose -n 100 -max 512 -m l1_dcm -f $1
./matrixMultiply -a simpleTranspose -n 100 -max 512 -m l2_dcm -f $1


./matrixMultiply -a 1d -n 100 -max 512 -m br_msp -f $1
./matrixMultiply -a 1d -n 100 -max 512 -m br_cn -f $1
./matrixMultiply -a 1d -n 100 -max 512 -m l1_dcm -f $1
./matrixMultiply -a 1d -n 100 -max 512 -m l2_dcm -f $1


./matrixMultiply -a 1dTranspose -n 100 -max 512 -m br_msp -f $1
./matrixMultiply -a 1dTranspose -n 100 -max 512 -m br_cn -f $1
./matrixMultiply -a 1dTranspose -n 100 -max 512 -m l1_dcm -f $1
./matrixMultiply -a 1dTranspose -n 100 -max 512 -m l2_dcm -f $1