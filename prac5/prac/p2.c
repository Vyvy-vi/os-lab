#include <stdio.h>
#include <unistd.h>

int main(void) {
  int child1 = fork();
  
  if (child1 == 0) {
    int child2 = fork();
    if (child2 == 0) {
      printf("p3 with pid: %d from parent with pid: %d\n", getpid(), getppid());
    } else {
      printf("p2 with pid: %d from parent with pid: %d\n", getpid(), getppid());
    }
  } else {
    printf("p1 with pid: %d from parent with pid: %d\n", getpid(), getppid());
    sleep(1);
  }
}
