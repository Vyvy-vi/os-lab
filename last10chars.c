#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
  int fd = open("input.txt", O_RDONLY, 0666);
  lseek(fd, -10, SEEK_END);

  char buff[10];
  read(fd, buff, 10);
  printf("%s\n", buff);
}
