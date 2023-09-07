#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
  pid_t pid = getpid();

  printf("Current process PID is %d\n", pid);
  printf("FOrking a child...\n");

  int status;
  pid_t child_pid = fork();

  if (child_pid == -1) {
    printf("Failed to fork child\n");
    exit(1);
  }
  else if (child_pid == 0) {
    printf("Child process running, Child process pid: %d, parent process pid: %d\n", getpid(), getppid());
    sleep(2);
    printf("Child process exiting\n");
    exit(0);
  } else {
    printf("Parent Process pid: %d\n", getpid());
    wait(&status);
    printf("Child exited with status: %d\n", status);
  }

  return 0;
}
