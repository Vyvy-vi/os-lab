#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int shared = 5;

sem_t s;

void *fun1() {
	int local;
	sem_wait(&s);
	local = shared;
	local++;
	sleep(5);
	shared = local;
	sem_post(&s);
	printf("Shared in fun1: %d\n", shared);
	pthread_exit(NULL);
}

void *fun2() {
	int local;
	sem_wait(&s);
	local = shared;
	local--;
	sleep(5);
	shared = local;
	sem_post(&s);
	printf("Shared in fun2: %d\n", shared);
	pthread_exit(NULL);
}

int main() {
	pthread_t t1, t2;
	sem_init(&s, 0, 1);
	pthread_create(&t1, NULL, fun1, NULL);
	pthread_create(&t2, NULL, fun2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}
