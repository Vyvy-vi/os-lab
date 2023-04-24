#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t locker;

int main()
{
if( pthread_mutex_init(&locker,NULL) == 0)
{
printf("Mutex created successfully \n");
}

if( pthread_mutex_lock(&locker) ==0)
{
printf("Mutex lock is put\n");
printf("Inside critical section\n");
}

if(pthread_mutex_unlock(&locker) ==0)
{
printf("Mutex lock is unlocked \n");
}

if( pthread_mutex_destroy(&locker)==0)
{
printf("Mutex lock destroyed successfully\n");
}
}
 
