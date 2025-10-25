#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int aleatorio(int min, int max) {
    // garante que o min seja menor que o max
    if (min>max) {
        int temp = min;
        min = max;
        max = temp;
    }
    return (rand() % (max - min + 1) + min);
}

int main(int argc, char *argv[]) {

    srand(time(NULL)); // Gerar valor aleatorio

    int min = atoi(argv[1]);
    int max = atoi(argv[2]);

    int number = aleatorio(min, max);

    int input;
    printf("Valor para apostar: ");
    scanf("%d", &input);

    while (input != number) {
        printf("Errado! ");
        if (input>number){
            printf("Alto! Tente novamente: ");
        } else {
            printf("Baixo! Tente novamente: ");
        }
        scanf("%d", &input);
    }

    printf("PARBÉNS! Acertaste o valor %d!\n",number);

    return 0;
}