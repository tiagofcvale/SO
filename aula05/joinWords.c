#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc 
#include <ctype.h>

int main(int argc, char *argv[]) {

    size_t total = 0; // Calcular o espaço a alocar para a string resultado
    for (int i = 1; i < argc; i++ )   {
        if (isalpha(argv[i][0])) { // se começar com número, passa 
            total+= strlen(argv[i]);
        }
    }

    char* res = malloc(total);

    for (int i = 1; i < argc; i++) {
        if (isalpha(argv[i][0])) { // se começar com número, passa
            strcat(res, argv[i]);
        }
    }
    printf("String resultante: %s\n",res);
}