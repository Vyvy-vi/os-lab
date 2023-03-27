#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
  pid_t p;

  int p2 = fork();

  if (p2 == 0)
  {
    int p3 = fork();
    if (p3 == 0) {
      printf("p3 with id: %d from parent with id: %d\n", getpid(), getppid());
    } else {
      printf("p2 with id: %d from parent with id: %d\n", getpid(), getppid());
    }
  }
  else {
    int p4 = fork();

    if (p4 == 0) {
      sleep(10);
      int p5 = fork();

      if (p5 == 0) {
        printf("p5 with id: %d from parent with id: %d\n", getpid(), getppid());
        exit(0);
      } else {
        printf("p4 with id: %d from parent with id: %d\n", getpid(), getppid());
        sleep(10);
      }
    } else if (p2 != 0 && p4 != 0) {
      sleep(1);
      printf("p1 with id: %d from parent with id: %d\n", getpid(), getppid());
    }
  }
}
