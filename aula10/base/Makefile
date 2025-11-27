CC = gcc

CFLAGS = -Wall

LDFLAGS = -lm

SEMAPHORE_OBJ = semaphore.o  # Arquivo de objeto do semáforo

.PHONY: all clean cleanall

all: reg-cri

# Compilação do executável final
reg-cri: sharedMemory.o reg-cri.o ${SEMAPHORE_OBJ}
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}

# Compilação de reg-cri.o
reg-cri.o: reg-cri.c sharedMemory.h
	${CC} ${CFLAGS} -c -o $@ $<

# Compilação de semaphore.o
semaphore.o: semaphore.c semaphore.h
	${CC} ${CFLAGS} -c -o $@ $<

clean:
	rm -f *.o *~

cleanall: clean
	rm -f reg-cri
