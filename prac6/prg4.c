#include <pthread>
#include <stdio.h>
#include <unistd.h>

struct arg_struct {
	int arg1;
	int arg2;
}

void *first(void * args) {
	struct arg_struct * args = args;
	printf("%d\n", args->arg1):
	printf("%d\n", args->arg2):
}

int main() {
	
}
