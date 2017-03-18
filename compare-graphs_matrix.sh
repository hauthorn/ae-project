#!/usr/bin/env bash

prefix="set key on left; set term png size 1200,800; set xlabel \"Size of matrix\"; set ylabel \"y / (n³)\"; set output 'runs/$1/$1_comparison"

# Comparison of runtime
#gnuplot -e  "${prefix}_runtime.png';
#			plot 'runs/$1/$1_simple.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d\", \
#			    'runs/$1/$1_simpleTranspose.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"


# Comparison of dcm
#gnuplot -e "${prefix}_l1_dcm.png';#
#			plot 'runs/$1/$1_simple_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d\", \
#			    'runs/$1/$1_simpleTranspose_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"

# Comparison of l2 dcm
#gnuplot -e "${prefix}_l2_dcm.png';
#			plot 'runs/$1/$1_simple_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d\", \
#			    'runs/$1/$1_simpleTranspose_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"

# Comparison of runtime between all algorithms
gnuplot -e  "${prefix}_runtime.png';set logscale y;
            plot 'runs/$1/$1_1d.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 1d\", \
                'runs/$1/$1_1dTranspose.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 1d Transposed\", \
                'runs/$1/$1_matrixTile.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix tile\", \
                'runs/$1/$1_matrixRecursive.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix Recursive\", \
                'runs/$1/$1_simpleTranspose.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"


gnuplot -e  "${prefix}_simple_simpleTranspose_runtime.png';
            plot 'runs/$1/$1_simple.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 2d\", \
                'runs/$1/$1_simpleTranspose.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"


gnuplot -e  "${prefix}_simple_simpleTranspose_l1_dcm.png';
            plot 'runs/$1/$1_simple_l1_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 2d\", \
                'runs/$1/$1_simpleTranspose_l1_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"

gnuplot -e  "${prefix}_simple_simpleTranspose_l2_dcm.png';
            plot 'runs/$1/$1_simple_l2_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 2d\", \
                'runs/$1/$1_simpleTranspose_l1_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"


gnuplot -e  "${prefix}_l1_dcm.png';
            plot 'runs/$1/$1_1dTranspose_l1_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 1d Transposed\", \
                'runs/$1/$1_matrixTile_l1_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix tile\", \
                'runs/$1/$1_matrixRecursive_l1_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix recursive\", \
                'runs/$1/$1_simpleTranspose_l1_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"


# Comparison of dcm using 1:(\$2/(\$1*log(\$1)))
gnuplot -e  "${prefix}_l2_dcm.png';
            plot 'runs/$1/$1_1dTranspose_l2_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 1d Transposed\", \
                'runs/$1/$1_matrixTile_l2_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix tile\", \
                'runs/$1/$1_matrixRecursive_l2_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix recursive\", \
                'runs/$1/$1_simpleTranspose_l2_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"


# Comparison of l1 dcm fo
gnuplot -e "${prefix}_1d_2d_l1_dcm.png';
            plot 'runs/$1/$1_1d_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 1d\", \
            'runs/$1/$1_simple_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d\";"


# Comparison of l2 dcm simple
gnuplot -e "${prefix}_1d_2d_l2_dcm.png';
            plot 'runs/$1/$1_1d_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 1d\", \
            'runs/$1/$1_simple_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d\";"

# Comparison of l1 dcm tran
gnuplot -e "${prefix}_1dTranspose_2dTranspose_l1_dcm.png';
            plot 'runs/$1/$1_1dTranspose_l1_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 1d transposed\", \
            'runs/$1/$1_simpleTranspose_l1_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"

# Comparison of l2 dcm
gnuplot -e "${prefix}_1dTranspose_2dTranspose_l2_dcm.png';
            plot 'runs/$1/$1_1dTranspose_l2_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 1d transposed\", \
            'runs/$1/$1_simpleTranspose_l2_dcm.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"

# Comparison of runningtime
gnuplot -e "${prefix}_1dTranspose_2dTranspose_runtime.png';
            plot 'runs/$1/$1_1dTranspose.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 1d transposed\", \
            'runs/$1/$1_simpleTranspose.txt' using 1:(\$2/(\$1*\$1*\$1)) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"




# Comparison of runtime
#gnuplot -e  "${prefix}_recursive_runtime.png';
#            plot 'runs/$1/$1_matrixRecursive.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication recursive\", \
#                'runs/$1/$1_simpleTranspose.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"


# Comparison of dcm
#gnuplot -e "${prefix}_recursive_l1_dcm.png';
#            plot 'runs/$1/$1_matrixRecursive_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication recursive\", \
#                'runs/$1/$1_simpleTranspose_l1_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"

# Comparison of l2 dcm
#gnuplot -e "${prefix}_recursive_l2_dcm.png';
#            plot 'runs/$1/$1_matrixRecursive_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication recursive\", \
#                'runs/$1/$1_simpleTranspose_l2_dcm.txt' using 1:(\$2/(\$1*log(\$1))) smooth frequency with linespoints title \"Matrix multiplication 2d transposed\";"
