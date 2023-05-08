#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  int fd = open("numbers.txt", O_CREAT | O_RDWR, 0666);

  int len = 2;
  for (int i = 1; i <= 100; i++) {
    if (i == 10 || i == 100) len++;
    char str[len];
    int p = sprintf(str, "%d", i);
    str[len - 1] = '\n';
    write(fd, str, len);
  }

  lseek(fd, 0, SEEK_SET);

  int size = 2;
  for (int i = 0; i < 10; i++) {
    if (i == 10) size++;
    char buff[size];
    read(fd, buff, size);
    printf("%s", buff);
  }
}
