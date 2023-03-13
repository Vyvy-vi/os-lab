#include <stdio.h>
#include <unistd.h>

int main(void) {
	int  pid;
	pid = getpid();

	printf("Parent process id is: %d\n", pid);
	printf("Creating a CHILD PROCESS.\n");

	pid = fork();
	printf("How are you? \n");

	if (pid == -1) {
		printf("Child process is nopt created.\n");
	} else if (pid == 0) {
		printf("HELLO\n");
		printf("Child proces is created and it's id is: %d", getpid());
	}

}
