#include <unistd.h>
#include <stdio.h>

#define N 3

int main() {
	// for (int i = 0; i < N; i++) fork();
	fork();
	fork();
	fork();
	printf("Hello\n");
}
