#!/bin/bash

num=$1
i=2

while [ $i -lt $num ]
do
	if [ $(($num % $i)) -eq 0 ]
	then 
		echo "$num is not prime"
		exit 0
	fi
	i=$(( $i + 1 ))
done

echo "$num is prime"
exit 0
