#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
	int pid;
	pid = getpid();

	printf("Current process pid is: %d\n", pid);
	printf("Forking a child process \n");
	pid = fork();

	if (pid == 0) {
		printf("Child process is sleeping\n");
		sleep(10);
		printf("Orphan child parent id: %d", getppid());
	} else {
		printf("parent process completed");
	}

	return 0;
}

