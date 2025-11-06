#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    int i;
    Person p = {35, 1.65, "xpto"};

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "wb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    int quantidade = 0;
    printf("Quantas pessoas pretende adicionar? \n");
    scanf("%d",&quantidade);

    /* Write 10 itens on a file */
    for(i = 1 ; i < quantidade + 1 ; i++)
    {    
        printf("Nome da %d pessoa: \n",i);
        scanf("%s",p.name);

        printf("Idade da %d pessoa: \n",i);
        scanf("%d",&p.age);

        printf("Altura da %d pessoa: \n",i);
        scanf("%le",&p.height);

        fwrite(&p, sizeof(Person), 1, fp);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
