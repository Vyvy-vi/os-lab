#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  if (argc < 2) 
  {
    printf("Please mention filename.\nUsage: ./a.out filename.ext\n");
    return 1;
  }

  int fd = open(argv[1], O_RDONLY);
  char buffer;

  int cap = 1000;
  int size = 0;
  char* str = (char *) malloc(cap);

  int n;

  while ((n = read(fd, &buffer, 1)) != 0) {
    if (size >= cap) {
      cap += 500;
      str = realloc(str, cap);
    } else {
      str[size] = buffer;
      size++;
    }
  }

  write(1, str, size);

  free(str);
}
