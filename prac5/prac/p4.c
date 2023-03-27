#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  pid_t p;

  int p2 = fork();

  if (p2 == 0)
  {
    int p3 = fork();
    if (p3 == 0) {
      int p4 = fork();
      if (p4 == 0) {
        sleep(10);
        printf("p4 with id: %d from parent with id: %d\n", getpid(), getppid());
      }
      else
        printf("p3 with id: %d from parent with id: %d\n", getpid(), getppid());
 
    } else {
      printf("p2 with id: %d from parent with id: %d\n", getpid(), getppid());
    }
  }
  else {
    int p5 = fork();

    if (p5 == 0) {
      int p6 = fork();

      if (p6 == 0) {
        int p7 = fork();
        if (p7 == 0) {
          printf("p7 with id: %d from parent with id: %d\n", getpid(), getppid());
        } else {
          printf("p6 with id: %d from parent with id: %d\n", getpid(), getppid());
          sleep(10);
        }
      } else {
        printf("p5 with id: %d from parent with id: %d\n", getpid(), getppid());
      }
    } else if (p2 != 0) {
      printf("p1 with id: %d from parent with id: %d\n", getpid(), getppid());
    }
  }
}
