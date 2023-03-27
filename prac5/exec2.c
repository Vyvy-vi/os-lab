#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("process id of exec2 is: %d\n", getpid());
	printf("Running exec2\n");

	return 0;
}
