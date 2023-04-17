#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define BUFF_SIZE 5 
#define true 1
#define false 0

int buff[BUFF_SIZE];
int add_index = 0;
int rem_index = 0;
int curr_size = 0;

pthread_mutex_t l;
pthread_cond_t c_cons;
pthread_cond_t c_prod;

void* producer() {
  for (int i = 0; i < 10; i++) {
    pthread_mutex_lock(&l);
    if (curr_size > BUFF_SIZE) {
      printf("Buffer Overflow");
      exit(1);
    }

    while (curr_size == BUFF_SIZE)
        pthread_cond_wait(&c_prod, &l);

    int val = add_index * 10;

    buff[add_index] = val; 

    add_index = (add_index + 1) % BUFF_SIZE;
    curr_size++;

    pthread_mutex_unlock(&l);
    pthread_cond_signal(&c_cons);

    printf("PRODUCER: added %d\n", val);

  }

  pthread_exit(NULL);
}

void* consumer() {
  while (true) {
    pthread_mutex_lock(&l);
    if (curr_size < 0) {
      printf("Buffer Underflow");
      exit(1);
    }

    while (curr_size == 0)
        pthread_cond_wait(&c_cons, &l);

    int val = buff[rem_index]; 

    rem_index = (rem_index + 1) % BUFF_SIZE;
    curr_size--;

    pthread_mutex_unlock(&l);
    pthread_cond_signal(&c_prod);

    printf("CONSUMER: removed %d\n", val);

  }

  pthread_exit(NULL);
}



int main() {
	pthread_t pt, ct;
	pthread_create(&pt, NULL, producer, NULL);
	pthread_create(&ct, NULL, consumer, NULL);
	pthread_join(pt, NULL);
	pthread_join(ct, NULL);
}
