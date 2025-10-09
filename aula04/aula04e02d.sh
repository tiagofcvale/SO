#!/bin/bash

function comparator() {
    if [[ "$1" -eq "$2" ]]; then
        return 1
    else
        return 0
    fi
}

echo "Digite dois números"
read num1
read num2
comparator $num1 $num2

valor_retorno=$?

if [[ $valor_retorno -eq 1 ]]; then
    echo "Números iguais"
else
    echo "Números diferentes"
fi