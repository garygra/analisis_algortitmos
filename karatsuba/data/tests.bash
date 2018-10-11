#!/usr/bin/bash

RANGE=10
number1=$RANDOM
let "number1 %= $RANGE"
number2=$RANDOM
let "number2 %= $RANGE"

for i in `seq 1 256`;
do
	OUTPUT="$(../build/karatsuba $number1 $number2)"
	echo "i: " $i " Number1: " $number1 " Number2: " $number2 " " $OUTPUT
	aux=$RANDOM
	let "aux %= $RANGE"
	number1=$number1$aux
	aux=$RANDOM
	let "aux %= $RANGE"
	number2=$number2$aux

done   

