#include <stdio.h>
#include <pthread.h>

void *factorial(void *arg) {
  int *x = (int *) arg;
  long fact = 1;
  for (int i = 1; i <= *x; i++) {
    fact *= i;
  }

  printf("Factorial: %ld\n", fact);

  pthread_exit(NULL);
}

void *even_odd(void *arg) {
  int *y = (int *) arg;
  
  int ret = *y % 2;

  if (ret == 0)
    printf("Even\n");
  else
    printf("Odd\n");

  pthread_exit(NULL);
}

int main() {
  pthread_t thread1, thread2;

  printf("Enter n: ");
  int n;
  scanf("%d", &n);

  pthread_create(&thread1, NULL, factorial, (void *)&n);
  pthread_create(&thread2, NULL, even_odd, (void *)&n);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
}
