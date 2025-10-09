#!/bin/bash
# For all the files in a folder, show their properties
if [[ $# -eq 1 && -d "$1" ]]
then
	for f in $1/*
	do
		file "$f"
	done
else
	echo "Mais do que 1 argumento ou ficheiro não é diretório"
fi
