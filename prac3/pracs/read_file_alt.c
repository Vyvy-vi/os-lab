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

  int n;

  while ((n = read(fd, &buffer, 1)) != 0) {
    write(1, &buffer, 1);
  }
}
