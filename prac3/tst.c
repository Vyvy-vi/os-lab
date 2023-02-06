#include <stdio.h>
#include <fcntl.h>

int main() {
	int fd;
	char buffer[10];
	fd = open("some.txt", O_CREAT | O_WRONLY, 0777);

	printf("The file desriptor is: %d\n", fd);
}
