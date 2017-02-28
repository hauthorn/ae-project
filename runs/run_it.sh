#!/usr/bin/env bash
#mkdir -p cmake-build-debug;
#cd cmake-build-debug;
cmake --build . --target ae_project -- -j 2;

# This fits in main memory of Anders' server
./ae_project -a binaryRecursive -n 10000 -max 250000000 -m br_msp -f it6;
./ae_project -a binaryRecursive -n 10000 -max 250000000 -m br_cn -f it6;
./ae_project -a binaryRecursive -n 10000 -max 250000000 -m l1_dcm -f it6;
./ae_project -a binaryRecursive -n 10000 -max 250000000 -m l2_dcm -f it6;
#./ae_project -a binaryRecursive -n 10000 -max 250000000 -m l3_dcm -f it6;
#./ae_project -a binaryRecursive -n 10000 -max 250000000 -m tlb_tl -f it6;

./ae_project -a binaryIterative -n 10000 -max 250000000 -m br_msp -f it6;
./ae_project -a binaryIterative -n 10000 -max 250000000 -m br_cn -f it6;
./ae_project -a binaryIterative -n 10000 -max 250000000 -m l1_dcm -f it6;
./ae_project -a binaryIterative -n 10000 -max 250000000 -m l2_dcm -f it6;
#./ae_project -a binaryIterative -n 10000 -max 250000000 -m l3_dcm -f it6;
#./ae_project -a binaryIterative -n 10000 -max 250000000 -m tlb_tl -f it6;