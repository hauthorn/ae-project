#!/usr/bin/env bash

prefix="set logscale x; set key on top; set term png size 1200,800; set xlabel \"Size of heap\"; set ylabel \"y / (n * log(n))\";set output 'runs/$1/$1_comparison"

# Comparison of runtime
gnuplot -e  "${prefix}_runtime.png'; set title \"Running time\";
			plot 'runs/$1/$1_binaryHeap.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Binary heap\", \
			    'runs/$1/$1_3heap.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"3-ary heap with loop\", \
			    'runs/$1/$1_4heap.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"4-ary heap with loop\", \
			    'runs/$1/$1_7heap.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"7-ary heap with loop\";"

# Comparison of br cn
gnuplot -e "${prefix}_br_cn.png'; set title \"Number of branches\";
            plot 'runs/$1/$1_binaryHeap_br_cn.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Binary heap\", \
                            'runs/$1/$1_3heap_br_cn.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"3-ary heap with loop\", \
                            'runs/$1/$1_4heap_br_cn.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"4-ary heap with loop\", \
                            'runs/$1/$1_7heap_br_cn.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"7-ary heap with loop\";"

# Comparison of br msp
gnuplot -e "${prefix}_br_msp.png'; set title \"Branch mispredictions\";
            plot 'runs/$1/$1_binaryHeap_br_msp.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Binary heap\", \
                            'runs/$1/$1_3heap_br_msp.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"3-ary heap with loop\", \
                            'runs/$1/$1_4heap_br_msp.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"4-ary heap with loop\", \
                            'runs/$1/$1_7heap_br_msp.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"7-ary heap with loop\";"

# Comparison of dcm
gnuplot -e "${prefix}_l1_dcm.png'; set title \"Level 1 data cache misses\";
            plot 'runs/$1/$1_binaryHeap_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Binary heap\", \
                            'runs/$1/$1_3heap_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"3-ary heap with loop\", \
                            'runs/$1/$1_4heap_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"4-ary heap with loop\", \
                            'runs/$1/$1_7heap_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"7-ary heap with loop\";"

# Comparison of l2 dcm
gnuplot -e "${prefix}_l2_dcm.png'; set title \"Level 2 data cache misses\";
            plot 'runs/$1/$1_binaryHeap_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Binary heap\", \
                            'runs/$1/$1_3heap_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"3-ary heap with loop\", \
                            'runs/$1/$1_4heap_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"4-ary heap with loop\", \
                            'runs/$1/$1_7heap_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"7-ary heap with loop\";"
