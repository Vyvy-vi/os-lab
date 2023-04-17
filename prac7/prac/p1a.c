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

void* producer() {
  while (curr_size <= BUFF_SIZE) {  
    pthread_mutex_lock(&l);
    int val;
    if (curr_size == 0) {
      val = add_index * 10;

      buff[add_index] = val; 
      add_index = (add_index + 1) % BUFF_SIZE;
      curr_size++;
    }
    pthread_mutex_unlock(&l);
    printf("PRODUCER: added %d\n", val);  
  }

  pthread_exit(NULL);
}

void* consumer() {
  while (curr_size >= 0) {
    pthread_mutex_lock(&l);
    int val;
    if (curr_size > 0) {
      val = buff[rem_index]; 

      rem_index = (rem_index + 1) % BUFF_SIZE;
      curr_size--;
    }
    pthread_mutex_unlock(&l);
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
