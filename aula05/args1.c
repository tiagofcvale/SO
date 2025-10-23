#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) { // 3 -> 2 argumentos + 1 ./args1
        printf("ERRO! Devem ser introduzidos exatamente 2 argumentos\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < argc; i++)
        printf("Argument %02d: \"%s\"\n",i,argv[i]);
}
