#!/bin/bash
# This script checks the existence of a file

if [[ $# == 1 ]]

then
	echo "Checking..."
	if [[ -f $1 ]]
	
	then
		echo "$1 existe."
		else
		echo "$1 não existe"
	fi
	echo "...done."

else
	echo "Demasiados argumentos"
fi


