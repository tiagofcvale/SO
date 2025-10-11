#!/bin/bash

read -a lista < "$1" #a -> ler por linha

for (( k=${#lista[@]}-1; k>0; k-- )); do #k=comprimento do array
    indMax=0
    for (( i=1; i<=k; i++ )); do
        if [[ ${lista[$i]} -ge ${lista[indMax]} ]]; then
            indMax="$i"
        fi
    done
    if [[ $indMax -ne $k ]]; then
        #swap
        temp="${lista[$indMax]}"
        lista[indMax]="${lista[$k]}"
        lista[k]="$temp"
    fi
done

echo "sorted vals: ${lista[@]}"
