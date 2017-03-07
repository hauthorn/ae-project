#!/usr/bin/env bash
cd ..;
cmake --build . --target ae_project -- -j 2;

# This fits in main memory of Anders' server
./ae_project -a binaryRecursive -n 10000 -max 250000000 -m br_msp -f $1;
./ae_project -a binaryRecursive -n 10000 -max 250000000 -m br_cn -f $1;
./ae_project -a binaryRecursive -n 10000 -max 250000000 -m l1_dcm -f $1;
./ae_project -a binaryRecursive -n 10000 -max 250000000 -m l2_dcm -f $1;

./ae_project -a binaryIterative -n 10000 -max 250000000 -m br_msp -f $1;
./ae_project -a binaryIterative -n 10000 -max 250000000 -m br_cn -f $1;
./ae_project -a binaryIterative -n 10000 -max 250000000 -m l1_dcm -f $1;
./ae_project -a binaryIterative -n 10000 -max 250000000 -m l2_dcm -f $1;

./ae_project -a binaryBFS -n 10000 -max 250000000 -m br_msp -f $1;
./ae_project -a binaryBFS -n 10000 -max 250000000 -m br_cn -f $1;
./ae_project -a binaryBFS -n 10000 -max 250000000 -m l1_dcm -f $1;
./ae_project -a binaryBFS -n 10000 -max 250000000 -m l2_dcm -f $1;