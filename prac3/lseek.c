#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(void) {
  int n, fd1;
  char buff[20];

  fd1 = open("abc.txt", O_RDONLY);
  lseek(fd1, 5, SEEK_SET);
  n = read(fd1, buff, 19);
  write(1, buff, n);
}
