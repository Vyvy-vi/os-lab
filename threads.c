#include <pthread.h>
#include <stdio.h>

void * func() {
  printf("In thread function\n");
  pthread_exit("Exit thread function\n");
}

int main() {
  pthread_t thread1;
  void *a;

  pthread_create(&thread1, NULL, func, NULL);
  pthread_join(thread1, &a);
  printf("%s\n", (char *) a);
  return 0;
}
