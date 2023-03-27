#include <stdio.h>
#include <pthread.h>

char *a;

void *func() {
	printf("In thread functiojn \n");
	pthread_exit("Exit thread function\n");
}
 
int main(void) {
	pthread_t thread1;
	void *a;
	printf("In main thread.\n");

	pthread_create(&thread1, NULL, func, NULL);
	pthread_join(thread1, &a);
	printf("%s \n", a);
}
