# TO RUN THIS SCRIPT:
# gnuplot -c plots.gnu dir_to_save 
# sst-rrt_rand_file sst-rrt_bang_file dirt_rand_file dirt_bang_file "(x_g, y_g, th_g)"

set encoding utf8
set key left
set terminal postscript enhanced eps color

set output "2tarea_plot.eps"
set title "Algoritmos de Ordenamiento"
set xlabel "N"
set ylabel 'Tiempo (s)'
set logscale x 2 
# set xrange [1:20]
set logscale y 2
set xtics (1, 10000, 100000, 1000000) 
set xtics add ("0.0" 0.1) 
# f(x) = a*x**b;
# fit f(x) 'results.txt' using 1:2 via a,b

plot "results.txt" using 1:2 every ::1 with points lt 7 title "Inserción",\
	'' using 1:3 every ::1 with points lt 6 title "Mezcla"
	# f(x) with lines

  # plot "data.txt" using 1:5 every ::2 with linespoints linestyle 7
