#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("================================================\n");

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork falhou");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        execl("/bin/ls", "ls", "-la", NULL);

        perror("execl falhou");
        exit(EXIT_FAILURE);
    }

    // Processo pai espera
    wait(NULL);

    printf("================================================\n");

    return EXIT_SUCCESS;
}