# TO RUN THIS SCRIPT:
# gnuplot -c plots.gnu dir_to_save 
# sst-rrt_rand_file sst-rrt_bang_file dirt_rand_file dirt_bang_file "(x_g, y_g, th_g)"

set encoding utf8
set key left
set terminal postscript enhanced eps monochrome

set output "3tarea_plot.eps"
set title "Algoritmos de Ordenamiento"
set xlabel "N"
set ylabel 'Tiempo (s)'
set logscale x 2 
set logscale y 2
set format y "%s %c"
# unset ytics
# set xtics (1, 10000, 100000, 1000000) 
# set xtics add ("0.0" 0.1) 
# set offset 0.6,0.6,0,0
# set palette gray
set xrange [1:1000000]
# set yrange [1:]
fac(x) = (int(x)==0) ? 1.0 : int(x) * fac(int(x)-1.0)

f1(x) = (1.5)**x
f2(x) = x**3
f3(x) = (log(x)/log(2))**2
f4(x) = log(fac(x))/log(2) # log2(x!)   LISP
f5(x) = (2**2)**x
f6(x) = log(log(x))
f7(x) = x**(log(log(x)/log(2))/log(2))
f8(x) = 2**(log(x)/log(2))
f9(x) = fac(x)				# LISP
fa(x) = fac(log(x)/log(2))	# LISP
# fb(x) = fac(x) # ITERADO	  LISP
fc(x) = 2**x
fd(x) = x*log(x)/log(2)
set samples 1000
plot f1(x) with lines title "1.5^n",\
	 f2(x) with lines title "n^3",\
	 f3(x) with lines title "log_2^2(n)",\
	 "data/f4_data.txt" using 1:2 with lines title "log2(n!)",\
	 f5(x) with lines title "2^2^n",\
	 f6(x) with lines title "log_2 log_2 n",\
	 f7(x) with lines title "n^{log_2 log_2 n}",\
	 f8(x) with lines title "2^{log_2 n}",\
	 "data/f9_data.txt" using 1:2 with lines title "n!",\
	 "data/fa_data.txt" using 1:2 with lines title "(log2(n))!",\
	 "data/fb_data.txt" using 1:2 with lines title "log_2 log_2 n",\
	 fc(x) with lines title "2^n",\
	 fd(x) with lines title "n log_2 n"


set output "3tarea_plot_close.eps"
plot f2(x) with lines title "n^3",\
	 f3(x) with lines title "log_2^2(n)",\
	 "data/f4_data.txt" using 1:2 with lines title "log2(x!)",\
	 f6(x) with lines title "log_2 log_2 n",\
	 f7(x) with lines title "n^{log_2 log_2 n}",\
	 f8(x) with lines title "2^{log_2 n}",\
	 "data/fa_data.txt" using 1:2 with lines title "(log2(x))!",\
	 "data/fb_data.txt" using 1:2 with lines title "log_2 log_2 n",\
	 fd(x) with lines title "n log_2 n"


