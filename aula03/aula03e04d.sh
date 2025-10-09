#!/bin/bash
# aula03e04d.sh
# This script does a very simple test for checking disk space (using if/elif/else)

# Obter percentagem de ocupação máxima
space=$(df -h | awk '{print $5}' | grep % | grep -v Use | sort -n \
| tail -1 | cut -d "%" -f1 -)

echo "Largest occupied space = $space%"

# Verificar condições
if [[ $space -lt 70 ]]; then
    Message="All OK."
elif [[ $space -lt 90 ]]; then
    Message="Cleaning out. One partition is $space% full."
elif [[ $space -lt 99 ]]; then
    Message="Better buy a new disk. One partition is $space% full."
elif [[ $space -eq 99 ]]; then
    Message="I'm drowning here! There's a partition at $space%!"
else
    Message="I seem to be running with a non-existent disk..."
fi

echo "$Message"

