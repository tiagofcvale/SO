#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#define NTIMES 50

static void Interrupt (int);
static int count = 0;

int main(int argc, char *argv[])
{
    struct sigaction sigact;
    unsigned int i;

    /* altera a rotina de atendimento ao ^C */
    sigact.sa_handler = Interrupt;
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = 0;
    if (sigaction(SIGINT, &sigact, NULL) < 0) { 
        perror("Rotina de atendimento não instalada\n");
        return EXIT_FAILURE;
    }

    /* contador */
    printf("PID = %u\n", getpid());
    i = 0;
    while (i <= NTIMES) { 
       printf("\r%08u ", i++);
       fflush(stdout);
       sleep(1);
    }
    printf("\n");
 
    return EXIT_SUCCESS;
}

static void Interrupt(int signum){
    if (signum == SIGINT) {
    count++;
        if (count < 4) {
        printf("\n%d vezes. Calma!\n", count);
        } else if (count == 4) {
            printf("\nEsta foi a 4ª vez. A próxima termina o processo!\n");

            if (signal(SIGINT, SIG_DFL) == SIG_ERR) {
                perror("Não foi possível reinstalar SIG_DFL");
                exit(EXIT_FAILURE);
            }
        }
    }
    else {
        printf("Recebido um sinal inesperado!\n");
        exit(EXIT_FAILURE);
    }
}