/**
 * \brief The server
 * \details This server converts strings to upper case
 * \autores : Artur Pereira e José Luís Oliveira
 */

#include "comm.h"

#include <ctype.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(void)
{
    /* Creating communication channel */
    servOpenComm();

    /* the service */
    MESSAGE msg;
    while(1) {
        /* getting first message from queue, blocking if necessary */ 
        servReceive(&msg);

        /* sending converted message */
        servSend(&msg);
    }
    return 0;
}

