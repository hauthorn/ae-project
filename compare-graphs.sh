gnuplot -e "set logscale x; set logscale y;
			plot 'runs/$1/$1_binite.txt' using 1:2 smooth frequency with points, \
				'runs/$1/$1_binrec.txt' using 1:2 smooth frequency with points
				; pause -1"