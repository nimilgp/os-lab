#!/bin/bash

for element in $*
do
	echo $(($element * 2))
done

