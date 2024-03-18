#!/bin/bash

echo $1 occured
grep -io $1 $2 | wc -l
echo times in $2
#echo $1 occured $count times in $2
