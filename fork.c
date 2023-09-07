#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  pid_t pid = getpid();

  printf("Current process PID is %d\n", pid);
  printf("FOrking a child...\n");

  pid_t child_pid = fork();

  if (child_pid == -1) {
    printf("Failed to fork child\n");
    return 1;
  }
  else if (child_pid == 0) {
    printf("Child process pid: %d, parent process pid: %d\n", getpid(), getppid());
  } else {
    printf("Parent Process pid: %d\n", getpid());
  }

  return 0;
}
