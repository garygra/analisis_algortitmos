# TO RUN THIS SCRIPT:
# gnuplot -c plots.gnu dir_to_save 
# sst-rrt_rand_file sst-rrt_bang_file dirt_rand_file dirt_bang_file "(x_g, y_g, th_g)"

set encoding utf8
set key left
set terminal postscript enhanced eps monochrome

set output "2tarea_plot.eps"
set title "Algoritmos de Ordenamiento"
set xlabel "N"
set ylabel 'Tiempo (s)'
set logscale x 2 
set logscale y 2
set xtics (1, 10000, 100000, 1000000) 
set xtics add ("0.0" 0.1) 
set offset 0.6,0.6,0,0
set palette gray

plot "results_ave.txt" using 1:2 every ::1 with linespoints pt 7 lt 7 title "Inserción",\
	'' using 1:3 every ::1 with linespoints lt 3 lc 3 pt 9  title "Mezcla",\
	'' using 1:3:(sprintf("%.4f", $3)) every ::1 with labels center offset 0,1 notitle,\
	'' using 1:2:(sprintf("%.4f", $2)) every ::1 with labels center offset 1,-1 notitle
	# f(x) with lines

  # plot "data.txt" using 1:5 every ::2 with linespoints linestyle 7
