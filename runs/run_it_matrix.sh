#!/usr/bin/env bash
cd ..;
cmake --build . --target matrixMultiply -- -j 2;

# This fits in main memory of Anders' server
#./matrixMultiply -a simple -n 20 -max 1024 -m br_msp -f $1;
#./matrixMultiply -a simple -n 20 -max 1024 -m br_cn -f $1;
#./matrixMultiply -a simple -n 20 -max 1024 -m l1_dcm -f $1;
#./matrixMultiply -a simple -n 20 -max 1024 -m l2_dcm -f $1;

#./matrixMultiply -a simpleTranspose -n 20 -max 1024 -m br_msp -f $1
#./matrixMultiply -a simpleTranspose -n 20 -max 1024 -m br_cn -f $1
./matrixMultiply -a simple -n 20 -max 1800 -m l1_dcm -f $1
./matrixMultiply -a simple -n 20 -max 1800 -m l2_dcm -f $1

#./matrixMultiply -a simpleWithTransposed -n 20 -max 1800 -m br_msp -f $1
#./matrixMultiply -a simpleWithTransposed -n 20 -max 1800 -m br_cn -f $1
./matrixMultiply -a simpleWithTransposed -n 20 -max 1800 -m l1_dcm -f $1
./matrixMultiply -a simpleWithTransposed -n 20 -max 1800 -m l2_dcm -f $1
#
#
#./matrixMultiply -a 1d -n 20 -max 1024 -m br_msp -f $1
#./matrixMultiply -a 1d -n 20 -max 1024 -m br_cn -f $1
#./matrixMultiply -a 1d -n 20 -max 1024 -m l1_dcm -f $1
#./matrixMultiply -a 1d -n 20 -max 1024 -m l2_dcm -f $1
#
#
#./matrixMultiply -a 1dTranspose -n 20 -max 1024 -m br_msp -f $1
#./matrixMultiply -a 1dTranspose -n 20 -max 1024 -m br_cn -f $1
#./matrixMultiply -a 1dTranspose -n 20 -max 1024 -m l1_dcm -f $1
#./matrixMultiply -a 1dTranspose -n 20 -max 1024 -m l2_dcm -f $1