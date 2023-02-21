#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(void) {
  int n, fd;
  char buff[20];

  fd = open("bcd.txt", O_RDONLY);
  printf("bcd: %d\n", fd);
  fd = open("abc.txt", O_RDONLY);
  printf("abc: %d\n", fd);

  n = read(fd, buff, 15);
  write(1, buff, n);
}
