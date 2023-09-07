#include <pthread.h>
#include <stdio.h>

void *hello(void *i) {
  char *str = i;
  printf("Hello %s, this is in thread\n", str);
  return NULL;
}

int main() {
  void *status;
  pthread_t thread1;
  char* arg = "vyom";

  pthread_create(&thread1, NULL, hello, (void *) arg);
  pthread_join(thread1, &status);
  return 0;
}
