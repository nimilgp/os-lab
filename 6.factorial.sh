#!/bin/bash

num=$1
product=1

for((i=1; i<=num; i+=1));
do
	product=$((product*i))
done

echo $num! = $product

