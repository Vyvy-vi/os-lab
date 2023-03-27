include <stdio.h>
#include <unistd.h>

int main(void) {

  int initPid = getpid();
  int p1 = fork();

  if (getpid() == p1)
    fork();
  
  if (getppid() == p1)
    fork();


  if (getpid() != initPid)
    printf("%d %d\n", getpid(), getppid());
}
