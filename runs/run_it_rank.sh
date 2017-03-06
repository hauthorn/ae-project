#!/usr/bin/env bash
cd ..;
cmake --build . --target rankSelect -- -j 2;

# This fits in main memory of Anders' server
./rankSelect -q rank -n 1000000 -max 2500000000 -m br_msp -f $1;
./rankSelect -q rank -n 1000000 -max 2500000000 -m br_cn -f $1;
./rankSelect -q rank -n 1000000 -max 2500000000 -m l1_dcm -f $1;
./rankSelect -q rank -n 1000000 -max 2500000000 -m l2_dcm -f $1;

#./rankSelect -q select -n 1000000 -max 250000000 -m br_msp -f $1;
#./rankSelect -q select -n 1000000 -max 250000000 -m br_cn -f $1;
#./rankSelect -q select -n 1000000 -max 250000000 -m l1_dcm -f $1;
#./rankSelect -q select -n 1000000 -max 250000000 -m l2_dcm -f $1;