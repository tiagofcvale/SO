#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %.2f\n", p->name, p->age, p->height);
}

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    Person pessoas[100];
    int quantidade = 0;

    if (argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp = fopen(argv[1], "rb");
    if (fp != NULL)
    {
        while (fread(&pessoas[quantidade], sizeof(Person), 1, fp) == 1)
        {
            quantidade++;
        }
        fclose(fp);
    }
    else
    {
        perror("Aviso: ficheiro ainda não existe (será criado)");
    }

    printf("Atualmente há %d pessoas no ficheiro.\n", quantidade);

    int novas = 0;
    printf("Quantas pessoas quer adicionar ao ficheiro? (0 para cancelar): ");
    scanf("%d", &novas);

    assert(quantidade + novas <= 100);

    for (int i = 0; i < novas; i++)
    {
        printf("Nome da %da pessoa: ", i + 1);
        scanf("%63s", pessoas[quantidade + i].name);

        printf("Idade da %da pessoa: ", i + 1);
        scanf("%d", &pessoas[quantidade + i].age);

        printf("Altura da %da pessoa: ", i + 1);
        scanf("%lf", &pessoas[quantidade + i].height);
    }

    quantidade += novas;

    fp = fopen(argv[1], "ab");
    if (fp == NULL)
    {
        perror("Erro ao abrir ficheiro para escrita");
        return EXIT_FAILURE;
    }

    fwrite(pessoas, sizeof(Person), quantidade, fp);
    fclose(fp);

    /* Print */
    for (int i = 0; i < quantidade; i++)
    {
        printPersonInfo(&pessoas[i]);
    }

    return EXIT_SUCCESS;
}
