#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int buff[20];
int i=0;
pthread_mutex_t m;

void* producer()
{
pthread_mutex_lock(&m);

while(i==0)
{
buff[i]=1;
i++;
printf("produced\n");
}

pthread_mutex_unlock(&m);
}

void* consumer()
{
pthread_mutex_lock(&m);

while(i>0)
{
printf("consumed\n");
i--;
}
pthread_mutex_unlock(&m);
}

int main()
{
pthread_t t1,t2;
pthread_mutex_init(&m,NULL);

pthread_create(&t1,NULL,producer,NULL);
pthread_create(&t2,NULL,consumer,NULL);

int j=1;

while(j<=20)
{
pthread_join(t1,NULL);
pthread_join(t2,NULL);
}

return 0;
}

