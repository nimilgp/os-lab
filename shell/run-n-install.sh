#!/bin/bash

prog=/usr/bin/htop

if [ -f $prog ]
then
	echo program is available, running it
else
	echo program not availible, installing it...
	sudo pacman -Syu htop
fi
$prog
