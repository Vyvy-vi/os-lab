#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(void) {
  int n, fd1, fd2;
  char buff[20];

  fd1 = open("abc.txt", O_RDONLY);
  printf("fd of first file: %d\n", fd1);
  fd2 = open("abcd.txt", O_CREAT | O_WRONLY, 0666);
  printf("fd of second file: %d\n", fd2);
  
  while ((n=read(fd1, buff, 15)) != 0) {
    write(fd2, buff, n);
  }
}
