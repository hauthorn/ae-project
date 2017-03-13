#!/usr/bin/env bash
prefix="set logscale x; set key on top; set term png size 1200,800; set xlabel \"Size of heap\"; set ylabel \"y / (n * log(n))\";set output 'runs/$1/$1_comparison"

# Comparison of runtime
gnuplot -e  "${prefix}_runtime.png'; set title \"Running time\"; set key on bottom;
			plot 'runs/$1/$1_binaryHeap.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Binary heap\", \
			    'runs/$1/$1_ternaryheap.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 3-ary heap\", \
			    'runs/$1/$1_quadheap.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 4-ary heap\", \
			    'runs/$1/$1_sevenheap.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 7-ary heap\", \
			    'runs/$1/$1_eightheap.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 8-ary heap\", \
			    'runs/$1/$1_nineheap.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 9-ary heap\", \
			    'runs/$1/$1_tenheap.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 10-ary heap\", \
			    'runs/$1/$1_elevenheap.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 11-ary heap\";"

# Comparison of br cn
gnuplot -e "${prefix}_br_cn.png'; set title \"Number of branches\";
            plot 'runs/$1/$1_binaryHeap_br_cn.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Binary heap\", \
                            'runs/$1/$1_ternaryheap_br_cn.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 3-ary heap\", \
                            'runs/$1/$1_quadheap_br_cn.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 4-ary heap\", \
                            'runs/$1/$1_sevenheap_br_cn.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 7-ary heap\", \
                            'runs/$1/$1_eightheap_br_cn.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 8-ary heap\", \
                            'runs/$1/$1_nineheap_br_cn.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 9-ary heap\", \
                            'runs/$1/$1_tenheap_br_cn.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 10-ary heap\", \
                            'runs/$1/$1_elevenheap_br_cn.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 11-ary heap\";"

# Comparison of br msp
gnuplot -e "${prefix}_br_msp.png'; set title \"Branch mispredictions\";
            plot 'runs/$1/$1_binaryHeap_br_msp.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Binary heap\", \
                            'runs/$1/$1_ternaryheap_br_msp.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 3-ary heap\", \
                            'runs/$1/$1_quadheap_br_msp.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 4-ary heap\", \
                            'runs/$1/$1_sevenheap_br_msp.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 7-ary heap\", \
                            'runs/$1/$1_eightheap_br_msp.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 8-ary heap\", \
                            'runs/$1/$1_nineheap_br_msp.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 9-ary heap\", \
                            'runs/$1/$1_tenheap_br_msp.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 10-ary heap\", \
                            'runs/$1/$1_elevenheap_br_msp.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 11-ary heap\";"

# Comparison of dcm
gnuplot -e "${prefix}_l1_dcm.png'; set title \"Level 1 data cache misses\"; set key on left;
            plot 'runs/$1/$1_binaryHeap_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Binary heap\", \
                            'runs/$1/$1_ternaryheap_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 3-ary heap\", \
                            'runs/$1/$1_quadheap_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 4-ary heap\", \
                            'runs/$1/$1_sevenheap_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 7-ary heap\", \
                            'runs/$1/$1_eightheap_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 8-ary heap\", \
                            'runs/$1/$1_nineheap_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 9-ary heap\", \
                            'runs/$1/$1_tenheap_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 10-ary heap\", \
                            'runs/$1/$1_elevenheap_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 11-ary heap\";"

# Comparison of l2 dcm
gnuplot -e "${prefix}_l2_dcm.png'; set title \"Level 2 data cache misses\"; set key on left;
            plot 'runs/$1/$1_binaryHeap_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Binary heap\", \
                            'runs/$1/$1_ternaryheap_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 3-ary heap\", \
                            'runs/$1/$1_quadheap_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 4-ary heap\", \
                            'runs/$1/$1_sevenheap_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 7-ary heap\", \
                            'runs/$1/$1_eightheap_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 8-ary heap\", \
                            'runs/$1/$1_nineheap_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 9-ary heap\", \
                            'runs/$1/$1_tenheap_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 10-ary heap\", \
                            'runs/$1/$1_elevenheap_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Unfolded 11-ary heap\";"
