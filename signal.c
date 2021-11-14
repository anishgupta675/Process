#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void handler(int num) {
	write(STDOUT_FILENO, "I won't die!\n", 13);
}

void seghandler(int num) {
	write(STDOUT_FILENO, "Seg Fault!\n", 10);
}

int main() {
	struct sigaction sa;
	sa.sa_handler = handler;

	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);
	sigaction(SIGKILL, &sa, NULL);

	sa.sa_handler = seghandler;

	sigaction(SIGSEGV, &sa, NULL);

	while(1) {
		printf("Wasting your cycles. %d\n", getpid());
		sleep(1);
	}
	free(&sa);

	return 0;
}
