#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

int main() {
	if(fork() == 0) {
		printf("I'm childish.\n");
		execl("/bin/ls", "ls", "-al", NULL);
		printf("after execlp");
	} else {
		printf("I'm old and parental. %d\n", getpid());
	}
	return 0;
}
