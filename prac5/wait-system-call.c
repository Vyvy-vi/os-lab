#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	int pid;
	int status;

	pid = fork();

	if (pid == -1) {
		printf("Error: Failed to fork process.\n");
	} else if (pid == 0) {
		printf("Child process is running.\n");
		sleep(5);
		printf("Child process exiting.\n");
	} else {
		printf("Parent process waiting for child process.\n");
		wait(&status);
		printf("Child process exited with status: %d\n", status);
	}
}
