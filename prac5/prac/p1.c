#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int n = 1;
	if (argc > 1) {
		n = argv[1];
	}
	fork();
	printf("%d\n", n);

}
