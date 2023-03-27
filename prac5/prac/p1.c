#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define N 4

int main() {
  int pid;
  for (int i = 0; i < N; i++) {
    pid = fork();
  }
  printf(".\n");
}
