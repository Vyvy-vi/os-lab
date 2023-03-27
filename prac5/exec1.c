#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("process id of current process (exec1) is: \n", getpid());
	char *args[] = {"./exec2", NULL};

	execv(args[0], args);

	printf("Coming back to exec1\n");
}
