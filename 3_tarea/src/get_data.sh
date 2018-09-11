#! /usr/bin/bash

number=2

rm -f ../data/f4_data.txt
rm -f ../data/f9_data.txt
rm -f ../data/fa_data.txt
rm -f ../data/fb_data.txt

until [ $number -gt 2000000 ] 
do
	echo "Starting: "$number"."
	./calcs.lisp $number 1 >> ../data/f4_data.txt
	./calcs.lisp $number 2 >> ../data/f9_data.txt
	./calcs.lisp $number 3 >> ../data/fa_data.txt
	./calcs.lisp $number 4 >> ../data/fb_data.txt
  
  	number=$(($number * 2))
done