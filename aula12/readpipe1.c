#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char buf[1024];

    // Abrir o FIFO para leitura
    fp = fopen("myfifo1", "r");
    if (fp == NULL) {
        perror("Erro ao abrir o FIFO");
        return 1;
    }

    // Ler e imprimir o que está a ser escrito no FIFO
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        printf("Mensagem do FIFO: %s", buf);
    }

    // Fechar o FIFO
    fclose(fp);

    return 0;
}
