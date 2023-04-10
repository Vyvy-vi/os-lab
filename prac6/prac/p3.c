#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

void* thread_avg(void *arg);
void* thread_min(void * arg);
void* thread_max(void * arg);

#define N 10

int num[N];

int main(int argc, char *argv[]) {
	for (int i = 0; i < N; i++) {
		printf("Enter number #%d: ", i + 1);
		scanf("%d", &num[i]);
	}

	pthread_t t_minID;
	pthread_t t_maxID;
	pthread_t t_avgID;

	void* _min;
	void* _max;
	void* _avg;

	pthread_create(&t_minID, NULL, thread_min, (void *) num);
	pthread_create(&t_maxID, NULL, thread_max, (void *) num);
	pthread_create(&t_avgID, NULL, thread_avg, (void *) num);

	pthread_join(t_minID, &_min);
	pthread_join(t_maxID, &_max);
	pthread_join(t_avgID, &_avg);

	printf("Inside the main program.\n");
	printf("MIN Thread returns: %d\n", *((int *) _min));
	printf("MAX thread returns: %d\n", *((int *) _max));
	printf("AVG thread returns: %.2f\n", *((double *) _avg));
}


void* thread_avg(void *arg) {
	printf("Inside the AVG thread\n");
	int *x = arg;
	double *_avg = (double *) malloc(1);
 	
	*_avg = 0;	
	
	for (int i = 0; i < N; i++) {
		*_avg += x[i];
	}

	*_avg = *_avg / (double) N;

	pthread_exit(_avg);
}

void* thread_min(void *arg) {
	printf("Inside the MIN thread\n");
	int *x = arg;
	int *_min = (int *) malloc(1);
	*_min = INT_MAX;

	for (int i = 0; i < N; i++) {
		if (x[i] < *_min)
			*_min = x[i];
	}
	pthread_exit(_min);
}

void* thread_max(void * arg) {
	printf("Inside the MAX thread\n");
	int *x = arg;
	int *_max = (int *) malloc(1);
	*_max = INT_MIN;
	
	for (int i = 0; i < N; i++) {
		if (x[i] > *_max)
			*_max = x[i];
	}
	pthread_exit(_max);
}
