#!/usr/bin/env bash

prefix="set logscale x; set term png size 1200,800;set output 'runs/$1/$1_comparison"

# Comparison of runtime
gnuplot -e  "${prefix}_runtime.png'; set logscale x;
			plot '../$1/$1_rankSelectSpace_rank_l1_dcm.txt' using 1:2 with points;"
