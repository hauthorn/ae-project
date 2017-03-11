#!/usr/bin/env bash
cd ..;
cmake --build . --target min_heap -- -j 2;

./min_heap -a ternaryheap -n 100 -max 1000000 -m br_msp -f $1;
./min_heap -a ternaryheap -n 100 -max 1000000 -m br_cn -f $1;
./min_heap -a ternaryheap -n 100 -max 1000000 -m l1_dcm -f $1;
./min_heap -a ternaryheap -n 100 -max 1000000 -m l2_dcm -f $1;

./min_heap -a quadheap -n 100 -max 1000000 -m br_msp -f $1;
./min_heap -a quadheap -n 100 -max 1000000 -m br_cn -f $1;
./min_heap -a quadheap -n 100 -max 1000000 -m l1_dcm -f $1;
./min_heap -a quadheap -n 100 -max 1000000 -m l2_dcm -f $1;

./min_heap -a sevenheap -n 100 -max 1000000 -m br_msp -f $1;
./min_heap -a sevenheap -n 100 -max 1000000 -m br_cn -f $1;
./min_heap -a sevenheap -n 100 -max 1000000 -m l1_dcm -f $1;
./min_heap -a sevenheap -n 100 -max 1000000 -m l2_dcm -f $1;

./min_heap -a binaryheap -n 100 -max 1000000 -m br_msp -f $1;
./min_heap -a binaryheap -n 100 -max 1000000 -m br_cn -f $1;
./min_heap -a binaryheap -n 100 -max 1000000 -m l1_dcm -f $1;
./min_heap -a binaryheap -n 100 -max 1000000 -m l2_dcm -f $1;

./min_heap -a 3heap -n 100 -max 1000000 -m br_msp -f $1;
./min_heap -a 3heap -n 100 -max 1000000 -m br_cn -f $1;
./min_heap -a 3heap -n 100 -max 1000000 -m l1_dcm -f $1;
./min_heap -a 3heap -n 100 -max 1000000 -m l2_dcm -f $1;

./min_heap -a 4heap -n 100 -max 1000000 -m br_msp -f $1;
./min_heap -a 4heap -n 100 -max 1000000 -m br_cn -f $1;
./min_heap -a 4heap -n 100 -max 1000000 -m l1_dcm -f $1;
./min_heap -a 4heap -n 100 -max 1000000 -m l2_dcm -f $1;

./min_heap -a 7heap -n 100 -max 1000000 -m br_msp -f $1;
./min_heap -a 7heap -n 100 -max 1000000 -m br_cn -f $1;
./min_heap -a 7heap -n 100 -max 1000000 -m l1_dcm -f $1;
./min_heap -a 7heap -n 100 -max 1000000 -m l2_dcm -f $1;

./min_heap -a queueheap -n 100 -max 1000000 -m br_msp -f $1;
./min_heap -a queueheap -n 100 -max 1000000 -m br_cn -f $1;
./min_heap -a queueheap -n 100 -max 1000000 -m l1_dcm -f $1;
./min_heap -a queueheap -n 100 -max 1000000 -m l2_dcm -f $1;