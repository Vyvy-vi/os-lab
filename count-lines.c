#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  int fd = open("input.txt", O_RDONLY);
  if (fd < 0) {
    printf("FIle not found...");
    return 2;
  }

  char buf;

  int line_count = 0;
  while (0 != read(fd, &buf, 1)) {
    if (buf == '\n')
      line_count++;
  }
  printf("%d\n", line_count);
}
