#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int shared = 5;

void *fun1() {
	int local;
	local = shared;
	printf("Value of local before increment: %d\n", local);
	local = local + 1;
	printf("Value of local after increment: %d\n", local);
	sleep(3);
	shared = local;
	printf("Value of shared in fun1: %d\n", shared);
	pthread_exit(NULL);
}

void *fun2() {
	int local;
	local = shared;
	printf("Value of local variable before decrement: %d\n", local);
	local = local - 1;
	printf("Value of local variable after decrement: %d\n", local);
	sleep(3);
	shared = local;
	printf("Value of shared in fun2: %d\n", shared);
	pthread_exit(NULL);
}

int main() {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, fun1, NULL);
	pthread_create(&t2, NULL, fun2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}
