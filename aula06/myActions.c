#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man system
 man date
*/

int main(int argc, char *argv[])
{
    char text[1024];
    FILE *fp = NULL;

    fp = fopen("command.log", "w");

    if (fp == NULL) {
        perror("Erro ao abrir ou criar o arquivo");
        return EXIT_FAILURE;
    }

    do
    {
        printf("Command: ");
        scanf("%1023[^\n]%*c", text);

        /* system(const char *command) executes a command specified in command
            by calling /bin/sh -c command, and returns after the command has been
            completed.
        */
        if(strcmp(text, "end")) {
           printf("\n * Command to be executed: %s\n", text);
           printf("---------------------------------\n");
           system(text);
           printf("---------------------------------\n");
           fprintf(fp, "Command to be executed: %s\n", text);
           fprintf(fp, "---------------------------------");
           fprintf(fp, system(text));
           fprintf(fp, "---------------------------------");
        }
    } while(strcmp(text, "end"));
    fclose(fp);
    printf("-----------The End---------------\n");

    return EXIT_SUCCESS;
}
