#!/usr/bin/env bash
cd ..;
cmake --build . --target min_heap -- -j 2;

# This fits in main memory of Anders' server
./min_heap -a binaryheap -n 10000 -max 50000000 -m br_msp -f $1;
./min_heap -a binaryheap -n 10000 -max 50000000 -m br_cn -f $1;
./min_heap -a binaryheap -n 10000 -max 50000000 -m l1_dcm -f $1;
./min_heap -a binaryheap -n 10000 -max 50000000 -m l2_dcm -f $1;

./min_heap -a 3heap -n 10000 -max 50000000 -m br_msp -f $1;
./min_heap -a 3heap -n 10000 -max 50000000 -m br_cn -f $1;
./min_heap -a 3heap -n 10000 -max 50000000 -m l1_dcm -f $1;
./min_heap -a 3heap -n 10000 -max 50000000 -m l2_dcm -f $1;

./min_heap -a 4heap -n 10000 -max 50000000 -m br_msp -f $1;
./min_heap -a 4heap -n 10000 -max 50000000 -m br_cn -f $1;
./min_heap -a 4heap -n 10000 -max 50000000 -m l1_dcm -f $1;
./min_heap -a 4heap -n 10000 -max 50000000 -m l2_dcm -f $1;

./min_heap -a 7heap -n 10000 -max 50000000 -m br_msp -f $1;
./min_heap -a 7heap -n 10000 -max 50000000 -m br_cn -f $1;
./min_heap -a 7heap -n 10000 -max 50000000 -m l1_dcm -f $1;
./min_heap -a 7heap -n 10000 -max 50000000 -m l2_dcm -f $1;

./min_heap -a queueheap -n 10000 -max 50000000 -m br_msp -f $1;
./min_heap -a queueheap -n 10000 -max 50000000 -m br_cn -f $1;
./min_heap -a queueheap -n 10000 -max 50000000 -m l1_dcm -f $1;
./min_heap -a queueheap -n 10000 -max 50000000 -m l2_dcm -f $1;