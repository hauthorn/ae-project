#!/usr/bin/env bash
#mkdir -p cmake-build-debug;
#cd cmake-build-debug;
cmake --build . --target ae_project -- -j 2;

# run take make sure that binarySearch iterative is as fast with arrays as with vectors

./ae_project -a binaryIterativeArray -n 1000 -max 250000000 -m br_msp -f it4;
./ae_project -a binaryIterativeArray -n 1000 -max 250000000 -m br_cn -f it4;
./ae_project -a binaryIterativeArray -n 1000 -max 250000000 -m l1_dcm -f it4;
./ae_project -a binaryIterativeArray -n 1000 -max 250000000 -m l2_dcm -f it4;