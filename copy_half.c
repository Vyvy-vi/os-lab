#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  int fd = open("input.txt", O_RDONLY);
  int halfsize = lseek(fd, 0, SEEK_END) / 2;
  lseek(fd, halfsize, SEEK_SET);
  char buff[halfsize];
  read(fd, buff, halfsize);

  printf("%s", buff);
}
