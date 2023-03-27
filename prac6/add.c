#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void *thread_add(void *arg);
int num[2];

int main(int argc, char *argv[]) {
	printf("Enter first number: ");
	scanf("%d", &num[0]);

	printf("Enter second number: ");
	scanf("%d", &num[1]);

	pthread_t tID;

	void * result;

	pthread_create(&tID, NULL, thread_add, (void *) num);
	pthread_join(tID, &result);
	printf("Inside the main program.\n");
	printf("Thread returns: %s", (char *) result);
}

void *thread_add(void *arg) {
	printf("Inside the thread\n");
	int *x = arg;
	int sum = x[0] + x[1];
	printf("Sum of numbers is: %d  \n", sum);
	pthread_exit("Sum is calculated");
}
