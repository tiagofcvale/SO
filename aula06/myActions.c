#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    char text[1024];
    FILE *fp = NULL;

    fp = fopen("command.log", "a");
    if (fp == NULL) {
        perror("Erro ao abrir ou criar o ficheiro");
        return EXIT_FAILURE;
    }

    while (1) {
        printf("Command: ");
        if (fgets(text, sizeof text, stdin) == NULL) { 
            putchar('\n');
            break;
        }

        size_t len = strcspn(text, "\n");
        text[len] = '\0';

        if (strcmp(text, "end") == 0) {
            break;
        }

        time_t now = time(NULL);
        struct tm *lt = localtime(&now);
        char timestr[64];
        if (lt != NULL) {
            strftime(timestr, sizeof timestr, "%Y-%m-%d %H:%M:%S", lt);
        } else {
            strncpy(timestr, "unknown-time", sizeof timestr);
            timestr[sizeof timestr - 1] = '\0';
        }

        
        printf("\n * Command to be executed: %s\n", text);
        printf("---------------------------------\n");
        system(text);
        printf("---------------------------------\n");

        fprintf(fp, "[%s] %s\n", timestr, text);
        fflush(fp); 
    }

    fclose(fp);
    printf("-----------The End---------------\n");
    return EXIT_SUCCESS;
}
