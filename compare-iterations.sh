#!/usr/bin/env bash
mkdir -p runs/$1$2;

prefix="set logscale x; set key on left; set term png size 1200,800;set output 'runs/$1$2/$1$2_comparison"

# Comparison of runtime
gnuplot -e  "${prefix}_runtime.png';
			plot 'runs/$1/$1_binite.txt' using 1:2 smooth frequency with points title \"$1 Binary search iterative\", \
			    'runs/$1/$1_binbfs.txt' using 1:2 smooth frequency with points title \"$1 Binary search BFS layout\", \
				'runs/$1/$1_binrec.txt' using 1:2 smooth frequency with points title \"$1 Binary search recursive\", \
				'runs/$2/$2_binite.txt' using 1:2 smooth frequency with points title \"$2 Binary search iterative\", \
			    'runs/$2/$2_binbfs.txt' using 1:2 smooth frequency with points title \"$2 Binary search BFS layout\", \
				'runs/$2/$2_binrec.txt' using 1:2 smooth frequency with points title \"$2 Binary search recursive\";"

# Comparison of br msp
gnuplot -e "${prefix}_br_msp.png';
			plot 'runs/$1/$1_binite_br_msp.txt' using 1:2 smooth frequency with points title \"$1 Binary search iterative\", \
			    'runs/$1/$1_binbfs_br_msp.txt' using 1:2 smooth frequency with points title \"$1 Binary search BFS layout\", \
				'runs/$1/$1_binrec_br_msp.txt' using 1:2 smooth frequency with points title \"$1 Binary search recursive\", \
				'runs/$2/$2_binite_br_msp.txt' using 1:2 smooth frequency with points title \"$2 Binary search iterative\", \
			    'runs/$2/$2_binbfs_br_msp.txt' using 1:2 smooth frequency with points title \"$2 Binary search BFS layout\", \
				'runs/$2/$2_binrec_br_msp.txt' using 1:2 smooth frequency with points title \"$2 Binary search recursive\";"

# Comparison of dcm
gnuplot -e "${prefix}_l1_dcm.png';
			plot 'runs/$1/$1_binite_l1_dcm.txt' using 1:2 smooth frequency with points title \"$1 Binary search iterative\", \
			    'runs/$1/$1_binbfs_l1_dcm.txt' using 1:2 smooth frequency with points title \"$1 Binary search BFS layout\", \
				'runs/$1/$1_binrec_l1_dcm.txt' using 1:2 smooth frequency with points title \"$1 Binary search recursive\", \
				'runs/$2/$2_binite_l1_dcm.txt' using 1:2 smooth frequency with points title \"$2 Binary search iterative\", \
			    'runs/$2/$2_binbfs_l1_dcm.txt' using 1:2 smooth frequency with points title \"$2 Binary search BFS layout\", \
				'runs/$2/$2_binrec_l1_dcm.txt' using 1:2 smooth frequency with points title \"$2 Binary search recursive\";"

# Comparison of l2 dcm
gnuplot -e "${prefix}_l2_dcm.png';
			plot 'runs/$1/$1_binite_l2_dcm.txt' using 1:2 smooth frequency with points title \"$1 Binary search iterative\", \
			    'runs/$1/$1_binbfs_l2_dcm.txt' using 1:2 smooth frequency with points title \"$1 Binary search BFS layout\", \
				'runs/$1/$1_binrec_l2_dcm.txt' using 1:2 smooth frequency with points title \"$1 Binary search recursive\", \
				'runs/$2/$2_binite_l2_dcm.txt' using 1:2 smooth frequency with points title \"$2 Binary search iterative\", \
			    'runs/$2/$2_binbfs_l2_dcm.txt' using 1:2 smooth frequency with points title \"$2 Binary search BFS layout\", \
				'runs/$2/$2_binrec_l2_dcm.txt' using 1:2 smooth frequency with points title \"$2 Binary search recursive\";"