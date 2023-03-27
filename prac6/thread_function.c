#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void * arg);
int i, j;

int main() {
	pthread_t IDthread;
	pthread_create(&IDthread, NULL, thread_function, NULL);
	pthread_join(IDthread, NULL);
	printf("Inside the main program\n");
	for (int i = 10; i < 15; i++) {
		printf("%d\n", i);
	}
}

void * thread_function(void * arg) {
	printf("Inside the thread\n");
	for (int j = 0; j < 5; j++) {
		printf("%d \n", j);
		sleep(1);
	}
}
