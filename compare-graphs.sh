#!/usr/bin/env bash

prefix="set logscale x; set term png size 1200,800;set output 'runs/$1/$1_comparison"

# Comparison of runtime
gnuplot -e  "${prefix}_runtime.png'; set logscale y;
			plot 'runs/$1/$1_binite.txt' using 1:2 smooth frequency with points, \
			    'runs/$1/$1_binbfs.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec.txt' using 1:2 smooth frequency with points;"

# Comparison of br cn
gnuplot -e "${prefix}_br_cn.png';
			plot 'runs/$1/$1_binite_br_cn.txt' using 1:2 smooth frequency with points, \
			    'runs/$1/$1_binbfs_br_cn.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec_br_cn.txt' using 1:2 smooth frequency with points;"

# Comparison of br msp
gnuplot -e "${prefix}_br_msp.png';
			plot 'runs/$1/$1_binite_br_msp.txt' using 1:2 smooth frequency with points, \
			    'runs/$1/$1_binbfs_br_msp.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec_br_msp.txt' using 1:2 smooth frequency with points;"

# Comparison of dcm
gnuplot -e "${prefix}_l1_dcm.png';
			plot 'runs/$1/$1_binite_l1_dcm.txt' using 1:2 smooth frequency with points, \
			    'runs/$1/$1_binbfs_l1_dcm.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec_l1_dcm.txt' using 1:2 smooth frequency with points;"

# Comparison of l2 dcm
gnuplot -e "${prefix}_l2_dcm.png';
			plot 'runs/$1/$1_binite_l2_dcm.txt' using 1:2 smooth frequency with points, \
			    'runs/$1/$1_binbfs_l2_dcm.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec_l2_dcm.txt' using 1:2 smooth frequency with points;"