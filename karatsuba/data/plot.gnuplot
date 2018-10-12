# TO RUN THIS SCRIPT:
# gnuplot -c plots.gnu dir_to_save 
# sst-rrt_rand_file sst-rrt_bang_file dirt_rand_file dirt_bang_file "(x_g, y_g, th_g)"

set encoding utf8
set key left
set terminal postscript enhanced eps monochrome

set output "karatsuba_cpp.eps"
set title "Multiplicación"
set xlabel "Dígitos"
set ylabel 'Tiempo (s)'
# set logscale x 2 
# set logscale y 2
# set format y "%s %c"
# unset ytics
# set xtics (1, 10000, 100000, 1000000) 
# set xtics add ("0.0" 0.1) 
# set offset 0.6,0.6,0,0
# set palette gray
set xrange [1:256]
set yrange [0:0.02]
fk(x) = 0.000005 * x**(log(3)/log(2))
fk2(x) = 0.000005 * x**(2)
# set samples 1000
plot fk(x) with lines title " {/Symbol Q}(n) = c n^{log_2 3}",\
	 fk2(x) with lines title " {/Symbol Q}(n) = c n^{2}",\
	 "mul_results.txt" using 2:10 with points title "Karatsuba"
	 # f5(x) with lines title "2^2^n",\
	 # f6(x) with lines title "log_2 log_2 n",\
	 # f7(x) with lines title "n^{log_2 log_2 n}",\
	 # f8(x) with lines title "2^{log_2 n}",\
	 # "data/f9_data.txt" using 1:2 with lines title "n!",\
	 # "data/fa_data.txt" using 1:2 with lines title "(log2(n))!",\
	 # "data/fb_data.txt" using 1:2 with lines title "log_2 log_2 n",\
	 # fc(x) with lines title "2^n",\
	 # fd(x) with lines title "n log_2 n"

# set xrange [1:10]
# unset yrange 

# set output "karatsuba_cpp_2.eps"
# plot fk(x) with lines title " {/Symbol Q}(n) = c n^{log_2 3}",\
# 	 fk2(x) with lines title " {/Symbol Q}(n) = c n^{2}",\
# 	 "mul_results.txt" using 2:10 with points title "Karatsuba",\
# 	 "normal_mul_results.txt" using 2:10 with points pt 2 title "Normal Multiplicacion"
# plot f2(x) with lines title "n^3",\
# 	 f3(x) with lines title "log_2^2(n)",\
# 	 "data/f4_data.txt" using 1:2 with lines title "log2(n!)",\
# 	 f6(x) with lines title "ln(ln(n))",\
# 	 f7(x) with lines title "n^{log_2 log_2 n}",\
# 	 f8(x) with lines title "2^{log_2 n}",\
# 	 "data/fa_data.txt" using 1:2 with lines title "(log2(n))!",\
# 	 "data/fb_data.txt" using 1:2 with lines title "log_2 log_2 n",\
# 	 fd(x) with lines title "n log_2 n"

# set output "3tarea_plot_close2.eps"
# plot f3(x) with lines title "log_2^2(n)",\
# 	 "data/f4_data.txt" using 1:2 with lines title "log2(n!)",\
# 	 f6(x) with lines title "ln(ln(n))",\
# 	 f8(x) with lines title "2^{log_2 n}",\
# 	 "data/fb_data.txt" using 1:2 with lines title "log_2 log_2 n",\
# 	 fd(x) with lines title "n log_2 n"
