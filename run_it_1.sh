#!/usr/bin/env bash
mkdir -p cmake-build-debug;
cd cmake-build-debug;
cmake --build . --target ae_project -- -j 2;
./ae_project -a linear -n 1000 -max 10000 -m br_msp -f it1;
./ae_project -a linear -n 1000 -max 10000 -m l2_dcm -f it1;

./ae_project -a binaryRecursive -n 1000 -max 10000 -m br_msp -f it1;
./ae_project -a binaryRecursive -n 1000 -max 10000 -m l2_dcm -f it1;

./ae_project -a binaryIterative -n 1000 -max 10000 -m br_msp -f it1;
./ae_project -a binaryIterative -n 1000 -max 10000 -m l2_dcm -f it1;
