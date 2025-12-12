#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char buf[1024];

    fp = popen("gzip > ficheiroGZ.gz", "w"); // "w" abrir o popen para escrita
    if(fp==NULL) {
        perror("Erro ao abrir o pipe");
        return 1;
    }

    while(fgets(buf, sizeof(buf), stdin)) { // enquanto receber texto (stdin) vai escrever na file
        fprintf(fp, "%s", buf);
    }
 
    fclose(fp);
    
    return 0;
}

