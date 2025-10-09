#!/bin/bash

function numeric_to_string() {
    case "$1" in
        1)
            echo "Um"
            return 1
            ;;
        2)
            echo "Dois"
            return 2
            ;;
        3)
            echo "Três"
            return 3
            ;;
        *)
            echo "Outro número"
            return 0
            ;;
    esac
}

# Chamada da função
numeric_to_string $1

valor_retorno=$?
echo "O valor de retorno foi: $valor_retorno"
