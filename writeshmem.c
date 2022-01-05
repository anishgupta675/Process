#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"shmem.h"

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("usage - %s [stuff to write]", argv[0]);
		return -1;
	}

	char *block = attach_memory_block(FILENAME, BLOCK_SIZE);
	if(block == NULL) {
		printf("ERROR: couldn't get block\n");
		return -1;
	}

	printf("Writing: \"%s\"\n", argv[1]);
	strncpy(block, argv[1], BLOCK_SIZE);

	detach_memory_block(block);

	return 0;
}
