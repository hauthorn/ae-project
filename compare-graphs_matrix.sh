#!/usr/bin/env bash

prefix="set logscale x; set key on left; set term png size 1200,800;set output 'runs/$1/$1_comparison"

# Comparison of runtime
gnuplot -e  "${prefix}_runtime.png';
			plot 'runs/$1/$1_simple.txt' using 1:2 smooth frequency with points title \"Binary search iterative\", \
			    'runs/$1/$1_simpleWithTransposed.txt' using 1:2 smooth frequency with points title \"Binary search BFS layout\";"


# Comparison of dcm
gnuplot -e "${prefix}_l1_dcm.png';
			plot 'runs/$1/$1_simple_l1_dcm.txt' using 1:2 smooth frequency with points title \"Binary search iterative\", \
			    'runs/$1/$1_simpleWithTransposed_l1_dcm.txt' using 1:2 smooth frequency with points title \"Binary search BFS layout\";"

# Comparison of l2 dcm
gnuplot -e "${prefix}_l2_dcm.png';
			plot 'runs/$1/$1_simple_l2_dcm.txt' using 1:2 smooth frequency with points title \"Binary search iterative\", \
			    'runs/$1/$1_simpleWithTransposed_l2_dcm.txt' using 1:2 smooth frequency with points title \"Binary search BFS layout\";"