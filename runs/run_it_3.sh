#!/usr/bin/env bash
#mkdir -p cmake-build-debug;
#cd cmake-build-debug;
cd ..
cmake --build . --target ae_project -- -j 2;

# This fits in main memory of Anders' server
./ae_project -a binaryRecursive -n 1000 -max 250000000 -m br_msp -f it3;
./ae_project -a binaryRecursive -n 1000 -max 250000000 -m br_cn -f it3;
./ae_project -a binaryRecursive -n 1000 -max 250000000 -m l1_dcm -f it3;
./ae_project -a binaryRecursive -n 1000 -max 250000000 -m l2_dcm -f it3;

./ae_project -a binaryIterative -n 1000 -max 250000000 -m br_msp -f it3;
./ae_project -a binaryIterative -n 1000 -max 250000000 -m br_cn -f it3;
./ae_project -a binaryIterative -n 1000 -max 250000000 -m l1_dcm -f it3;
./ae_project -a binaryIterative -n 1000 -max 250000000 -m l2_dcm -f it3;

./ae_project -a binaryTree -n 1000 -max 250000000 -m br_msp -f it3;
./ae_project -a binaryTree -n 1000 -max 250000000 -m br_cn -f it3;
./ae_project -a binaryTree -n 1000 -max 250000000 -m l1_dcm -f it3;
./ae_project -a binaryTree -n 1000 -max 250000000 -m l2_dcm -f it3;