#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
	pid_t a;
	a = fork();

	if (a > 0) {
		sleep(20);
		printf("PID of Parent: %d\n", getpid());
	} else {
		printf("PID of Child: %d\n", getpid());
		exit(0);
	}
}
