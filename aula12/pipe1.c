#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int fdp1[2], fdp2[2];
    char buf[1024];

    if(pipe(fdp1)!=0) {
        perror(argv[0]);
        return 1;
    }

    if(pipe(fdp2)!=0){
       perror(argv[0]);
       return 1;
    }

    switch(fork()) {
       case -1:
              perror(argv[0]);
              return 1;
       case 0: // FILHO
              close(fdp1[0]);
              close(fdp2[1]);  // O filho só vai ler no pipe2 e só vai escrever no pipe1
              write(fdp1[1],"Hello Dad!",11); //escreve no pipe1
              close(fdp1[1]); // fecha o pipe1
              read(fdp2[0],buf,1024); // lê no pipe2
              printf("Child: %s\n",buf); 
              break;
       default: // PAI
              close(fdp1[1]);
              close(fdp2[0]); // O pai só vai escrever no pipe2 e só vai ler no pipe1
              read(fdp1[0],buf,1024); // Lê no pipe1
              close(fdp1[0]); // fecha o pipe1
              write(fdp2[1],"Good Morning!",14); // Escreve no pipe2
              printf("Parent: %s\n",buf);
   }
   return 0;
}

