#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>
#include<wait.h>

int main() {

	while(true) {
		if(fork() == 0) {
			printf("child started...and done! (%d)\n", getpid());
			return 0;
		} else {
			wait(NULL);
			printf("parent just won't die...\n");
			sleep(5);
		}
	}
	return 0;

}
