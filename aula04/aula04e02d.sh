#!/bin/bash

function comparator() {
    if [[ "$1" -eq "$2" ]]; then
        return 0
    else
        if [[ "$1" -gt "$2" ]]; then
            return 1
        else
            return 2
        fi
    fi
}

echo "Digite dois números"
read num1 num2
comparator $num1 $num2

valor_retorno=$?

if [[ $valor_retorno -eq 0 ]]; then
    echo "Números iguais"
else
    if [[ $valor_retorno -eq 1 ]]; then
        echo "$num1 é maior"
    else 
        echo "$num2 é maior"
    fi
fi