#!/usr/bin/env bash

prefix="set key on left; set term png size 1200,800;set output 'runs/$1/$1_comparison"

# Comparison of runtime
gnuplot -e  "${prefix}_runtime.png';
			plot 'runs/$1/$1_simple.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d\", \
			    'runs/$1/$1_simpleWithTransposed.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"


# Comparison of dcm
gnuplot -e "${prefix}_l1_dcm.png';
			plot 'runs/$1/$1_simple_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d\", \
			    'runs/$1/$1_simpleWithTransposed_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"

# Comparison of l2 dcm
gnuplot -e "${prefix}_l2_dcm.png';
			plot 'runs/$1/$1_simple_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d\", \
			    'runs/$1/$1_simpleWithTransposed_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"

# Comparison of runtime between
gnuplot -e  "${prefix}_1d_runtime.png';
            plot 'runs/$1/$1_1d.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 1d\", \
                'runs/$1/$1_1dTranspose.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 1d Transposed\", \
                'runs/$1/$1_simpleWithTransposed.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"


# Comparison of dcm
gnuplot -e "${prefix}_1d_l1_dcm.png';
            plot 'runs/$1/$1_1d_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 1d\", \
            'runs/$1/$1_1dTranspose_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 1d Transposed\", \
                'runs/$1/$1_simpleWithTransposed_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"

# Comparison of l2 dcm
gnuplot -e "${prefix}_1d_l2_dcm.png';
            plot 'runs/$1/$1_1d_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 1d\", \
            'runs/$1/$1_1dTranspose_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 1d transposed\", \
                'runs/$1/$1_simpleWithTransposed_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"

# Comparison of runtime
gnuplot -e  "${prefix}_recursive_runtime.png';
            plot 'runs/$1/$1_matrixRecursive.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication recursive\", \
                'runs/$1/$1_simpleWithTransposed.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"


# Comparison of dcm
gnuplot -e "${prefix}_recursive_l1_dcm.png';
            plot 'runs/$1/$1_matrixRecursive_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication recursive\", \
                'runs/$1/$1_simpleWithTransposed_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"

# Comparison of l2 dcm
gnuplot -e "${prefix}_recursive_l2_dcm.png';
            plot 'runs/$1/$1_matrixRecursive_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication recursive\", \
                'runs/$1/$1_simpleWithTransposed_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"
