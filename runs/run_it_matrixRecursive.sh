#!/usr/bin/env bash
cd ..;
cmake --build . --target matrixRecursive -- -j 2;

./matrixRecursive -n 20 -max 2048 -m tot_iis -f $1;
./matrixRecursive -n 20 -max 2048 -m tlb_tl -f $1;

./matrixMultiply -a simpleTranspose -n 20 -max 1800 -m tot_iis -f $1
./matrixMultiply -a simpleTranspose -n 20 -max 1800 -m tlb_tl -f $1