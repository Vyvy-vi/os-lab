#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd1, fd2;
  
  fd1 = open("input.txt", O_RDONLY);
  if (fd1 < 0) {
    printf("File not found...");
    return 2;
  }
  int size = lseek(fd1, 0, SEEK_END);

  char buff[size];
  
  lseek(fd1, 0, SEEK_SET);
  read(fd1, buff, size);

  fd2 = open("output.txt", O_CREAT | O_WRONLY, 0666);
  write(fd2, buff, size);
}
