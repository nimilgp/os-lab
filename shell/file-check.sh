#!/bin/bash

file=$1

if [ -f $file ] 
then
	echo the file exists
else
	echo the file does not exist
fi
	
