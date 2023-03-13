#include <stdio.h>
#include <unistd.h>

int main() {
	int pid;
	pid = getpid();
	printf("Id of this process is %d.\n", pid);

	printf("Forking a child process...\n");
	pid = fork(); // creates 2^n - 1 children, where n is no  of fork called
	pid = fork();
	if (pid == -1) {
		printf("No child is created.\n");
	} else if (pid == 0) {
		printf("Child process id: %d and it's parent's id: %d.\n", getpid(), getppid());
	} else {
		printf("Only parent in thread.\n");
	}
}
