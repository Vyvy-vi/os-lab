#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void* thread_add(void *arg);
void* thread_multiply(void * arg);

int num[2];

int main(int argc, char *argv[]) {
	printf("Enter first number: ");
	scanf("%d", &num[0]);

	printf("Enter second number: ");
	scanf("%d", &num[1]);

	pthread_t t_addID;
	pthread_t t_multiplyID;

	void* sum;
	void* product;

	pthread_create(&t_addID, NULL, thread_add, (void *) num);
	pthread_create(&t_multiplyID, NULL, thread_multiply, (void *) num);

	pthread_join(t_addID, &sum);
	pthread_join(t_multiplyID, &product);
	
	printf("Inside the main program.\n");
	printf("Add Thread returns: %d\n", *((int *) sum));
	printf("Multiply thread returns: %d\n", *((int *) product));
}

void* thread_add(void *arg) {
	printf("Inside the ADD thread\n");
	int *x = arg;
	int *sum = (int *) malloc(1);
       	*sum =x[0] + x[1];
	printf("Sum of numbers is: %d  \n", *sum);
	pthread_exit(sum);
}

void* thread_multiply(void * arg) {
	printf("Inside the MULTIPLY thread\n");
	int *x = arg;
	int *product = (int *) malloc(1);
	*product = x[0] * x[1];
	printf("Product of numbers is: %d  \n", *product);
	pthread_exit(product);
}
