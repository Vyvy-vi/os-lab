#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N_READERS 5

int shared_var = 0; // shared variable
int read_count = 0; // number of readers currently reading
sem_t mutex; // semaphore for mutual exclusion of shared_var
sem_t read_sem; // semaphore for readers to wait for writer
sem_t write_sem; // semaphore for writer to wait for readers

void *reader(void *arg) {
    int id = *(int *)arg;

    while (1) {
        sem_wait(&mutex); // acquire mutex for read_count
        read_count++;
        if (read_count == 1) {
            sem_wait(&write_sem); // if first reader, wait for writer
        }
        sem_post(&mutex); // release mutex for read_count

        printf("Reader %d reads shared_var as %d\n", id, shared_var);

        sem_wait(&mutex); // acquire mutex for read_count
        read_count--;
        if (read_count == 0) {
            sem_post(&write_sem); // if last reader, signal writer
        }
        sem_post(&mutex); // release mutex for read_count

        sleep(rand() % 5); // reader does some work
    }

    pthread_exit(NULL);
}

void *writer(void *arg) {
    int id = *(int *)arg;

    while (1) {
        sem_wait(&read_sem); // wait for all readers to finish
        sem_wait(&mutex); // acquire mutex for shared_var

        printf("Writer %d writes shared_var as %d\n", id, ++shared_var);

        sem_post(&mutex); // release mutex for shared_var
        sem_post(&read_sem); // signal readers

        sleep(rand() % 5); // writer does some work
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t readers[N_READERS], writer_thread;
    int i, reader_ids[N_READERS], writer_id = 1;

    sem_init(&mutex, 0, 1); // initialize mutex to 1
    sem_init(&read_sem, 0, 0); // initialize read_sem to 0
    sem_init(&write_sem, 0, 1); // initialize write_sem to 1

    // create threads for readers
    for (i = 0; i < N_READERS; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, (void *)&reader_ids[i]);
    }

    // create thread for writer
    pthread_create(&writer_thread, NULL, writer, (void *)&writer_id);

    // wait for threads to finish
    for (i = 0; i < N_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    pthread_join(writer_thread, NULL);

    return 0;
}
