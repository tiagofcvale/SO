#include <stdio.h>
#include <stdlib.h> // atoi, atof
#include <math.h>   // pow()

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("ERRO! A formatação dos argumentos deve ser <número> <operação> <número>\n");
        return 1;
    }

    double valor1 = atof(argv[1]);
    char op = argv[2][0];
    double valor2 = atof(argv[3]);
    double res;

    switch (op) {
        case '+':
            res = valor1 + valor2;
            break;
        case '-':
            res = valor1 - valor2;
            break;
        case 'x':
            res = valor1 * valor2;
            break;
        case '/':
            if (valor2 == 0) {
                printf("Erro: divisão por zero!\n");
                return 1;
            }
            res = valor1 / valor2;
            break;
        case 'p':
            res = pow(valor1, valor2);
            break;
        default:
            printf("Operação inválida!\n");
            return 1;
    }

    printf("O resultado da tua operação é: %.4f\n", res);
    return 0;
}
