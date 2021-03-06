#include<stdio.h>
#include<unistd.h>
#include<stdint.h>
#include<sys/mman.h>
#include<stdlib.h>

#define PAGESIZE 4096

int main() {
	uint8_t *first = mmap(NULL, 4 * PAGESIZE, PROT_READ | PROT_WRITE,
															MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	uint8_t *second = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE,
															MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	printf("First: %p\n", first);
	printf("Second: %p\n", second);

	return 0;
}
