#!/usr/bin/env bash

prefix="set logscale x; set key on left; set term png size 1200,800;set output 'runs/$1/$1_comparison"

# Comparison of runtime
gnuplot -e  "${prefix}_runtime.png';
			plot 'runs/$1/$1_binaryHeap.txt' using 1:2 smooth frequency with points, \
			    'runs/$1/$1_3heap.txt' using 1:2 smooth frequency with points, \
			    'runs/$1/$1_4heap.txt' using 1:2 smooth frequency with points, \
			    'runs/$1/$1_7heap.txt' using 1:2 smooth frequency with points, \
			    'runs/$1/$1_ternaryheap.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_queueheap.txt' using 1:2 smooth frequency with points;"

# Comparison of br cn
gnuplot -e "${prefix}_br_cn.png';
            plot 'runs/$1/$1_binaryHeap_br_cn.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_3heap_br_cn.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_4heap_br_cn.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_7heap_br_cn.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_ternaryheap_br_cn.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_queueheap_br_cn.txt' using 1:2 smooth frequency with points;"

# Comparison of br msp
gnuplot -e "${prefix}_br_msp.png';
            plot 'runs/$1/$1_binaryHeap_br_msp.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_3heap_br_msp.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_4heap_br_msp.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_7heap_br_msp.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_ternaryheap_br_msp.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_queueheap_br_msp.txt' using 1:2 smooth frequency with points;"

# Comparison of dcm
gnuplot -e "${prefix}_l1_dcm.png';
            plot 'runs/$1/$1_binaryHeap_l1_dcm.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_3heap_l1_dcm.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_4heap_l1_dcm.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_7heap_l1_dcm.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_ternaryheap_l1_dcm.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_queueheap_l1_dcm.txt' using 1:2 smooth frequency with points;"

# Comparison of l2 dcm
gnuplot -e "${prefix}_l2_dcm.png';
            plot 'runs/$1/$1_binaryHeap_l2_dcm.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_3heap_l2_dcm.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_4heap_l2_dcm.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_7heap_l2_dcm.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_ternaryheap_l2_dcm.txt' using 1:2 smooth frequency with points, \
                            'runs/$1/$1_queueheap_l2_dcm.txt' using 1:2 smooth frequency with points;"