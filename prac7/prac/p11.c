#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0; // number of items in buffer
int in = 0; // index for next item to be produced
int out = 0; // index for next item to be consumed

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // initialize mutex
pthread_cond_t full = PTHREAD_COND_INITIALIZER; // initialize condition variable for full buffer
pthread_cond_t empty = PTHREAD_COND_INITIALIZER; // initialize condition variable for empty buffer

void *producer(void *arg) {
    int i, item;

    for (i = 0; i < BUFFER_SIZE; i++) {
        item = rand() % 100; // produce a random item
        pthread_mutex_lock(&mutex); // acquire mutex

        while (count == BUFFER_SIZE) { // if buffer is full, wait for consumer to consume
            pthread_cond_wait(&empty, &mutex);
        }

        buffer[in] = item; // write item to buffer
        in = (in + 1) % BUFFER_SIZE; // increment index

        count++; // increment count
        printf("Produced item %d\n", item);

        pthread_cond_signal(&full); // signal consumer that buffer is full
        pthread_mutex_unlock(&mutex); // release mutex
    }

    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int i, item;

    for (i = 0; i < BUFFER_SIZE; i++) {
        pthread_mutex_lock(&mutex); // acquire mutex

        while (count == 0) { // if buffer is empty, wait for producer to produce
            pthread_cond_wait(&full, &mutex);
        }

        item = buffer[out]; // read item from buffer
        out = (out + 1) % BUFFER_SIZE; // increment index

        count--; // decrement count
        printf("Consumed item %d\n", item);

        pthread_cond_signal(&empty); // signal producer that buffer is empty
        pthread_mutex_unlock(&mutex); // release mutex
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t prod, cons;

    // create threads for producer and consumer
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // wait for threads to finish
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    return 0;
}
