#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *sample_thread(void * arg) {
	printf("Inside thread\n");
	pthread_exit("Exiting from the thread");
}


int main(void) {
	pthread_t tID;
	void *a;
	pthread_create(&tID, NULL, sample_thread, NULL);
	pthread_join(tID, &a);
	printf("Inside the main program\n");

	printf("Thread return: %s\n", (char *) a);

}
