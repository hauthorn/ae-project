#!/usr/bin/env bash

# Comparison of runtime
gnuplot -e "plot 'runs/$1/$1_binite.txt' using 1:2 smooth frequency with points, \
                'runs/$1/$1_bintree.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec.txt' using 1:2 smooth frequency with points;
			MAX=GPVAL_Y_MAX;
    		MIN=GPVAL_Y_MIN;
			set yrange [MIN-(MAX-MIN)*0.01:MAX+(MAX-MIN)*0.20];
			set term png size 1200,800;set output 'runs/$1/$1_comparison_runtime.png';
			set logscale x; set logscale y;
			plot 'runs/$1/$1_binite.txt' using 1:2 smooth frequency with points, \
			    'runs/$1/$1_bintree.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec.txt' using 1:2 smooth frequency with points;"

# Comparison of br cn
gnuplot -e "plot 'runs/$1/$1_binite_br_cn.txt' using 1:2 smooth frequency with points, \
                'runs/$1/$1_bintree_br_cn.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec_br_cn.txt' using 1:2 smooth frequency with points;
			MAX=GPVAL_Y_MAX;
    		MIN=GPVAL_Y_MIN;
			set yrange [MIN-(MAX-MIN)*0.01:MAX+(MAX-MIN)*0.20];
			set term png size 1200,800;set output 'runs/$1/$1_comparison_br_cn.png';
			set logscale x; set logscale y;
			plot 'runs/$1/$1_binite_br_cn.txt' using 1:2 smooth frequency with points, \
			    'runs/$1/$1_bintree_br_cn.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec_br_cn.txt' using 1:2 smooth frequency with points;"


# Comparison of br msp
gnuplot -e "plot 'runs/$1/$1_binite_br_msp.txt' using 1:2 smooth frequency with points, \
                    'runs/$1/$1_binite_br_msp.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec_br_msp.txt' using 1:2 smooth frequency with points;
			MAX=GPVAL_Y_MAX;
    		MIN=GPVAL_Y_MIN;
			set yrange [MIN-(MAX-MIN)*0.01:MAX+(MAX-MIN)*0.20];
			set term png size 1200,800;set output 'runs/$1/$1_comparison_br_msp.png';
			set logscale x; set logscale y;
			plot 'runs/$1/$1_binite_br_msp.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec_br_msp.txt' using 1:2 smooth frequency with points;"


# Comparison of dcm
gnuplot -e "plot 'runs/$1/$1_binite_l1_dcm.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec_l1_dcm.txt' using 1:2 smooth frequency with points;
			MAX=GPVAL_Y_MAX;
    		MIN=GPVAL_Y_MIN;
			set yrange [MIN-(MAX-MIN)*0.01:MAX+(MAX-MIN)*0.20];
			set term png size 1200,800;set output 'runs/$1/$1_comparison_l1_dcm.png';
			set logscale x; set logscale y;
			plot 'runs/$1/$1_binite_l1_dcm.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec_l1_dcm.txt' using 1:2 smooth frequency with points;"

# Comparison of l2 dcm
gnuplot -e "plot 'runs/$1/$1_binite_l2_dcm.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec_l2_dcm.txt' using 1:2 smooth frequency with points;
			MAX=GPVAL_Y_MAX;
    		MIN=GPVAL_Y_MIN;
			set yrange [MIN-(MAX-MIN)*0.01:MAX+(MAX-MIN)*0.20];
			set term png size 1200,800;set output 'runs/$1/$1_comparison_l2_dcm.png';
			set logscale x; set logscale y;
			plot 'runs/$1/$1_binite_l2_dcm.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec_l2_dcm.txt' using 1:2 smooth frequency with points;"