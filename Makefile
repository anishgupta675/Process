CC=gcc
CFLAGS=-g -Wall -pthread -lpthread -lrt
OBJS=shmem.o
EXE=writesemaphore.elf readsemaphore.elf freeshmem.elf

all: $(EXE)

%.elf: %.o $(OBJS)
	$(CC) $(CFLAGS) $< $(OBJS) -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.dSYM *.o $(EXE)
