#include <stdio.h>
#include <unistd.h>

int main() {
	int pid;
	pid = getpid();
	printf("Id of this process is %d", pid);
}
