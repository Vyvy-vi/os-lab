#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  int fd = open("output.txt", O_CREAT | O_WRONLY, 0666);
  write(fd, "Hello World!", 12);
  close(fd);
}
