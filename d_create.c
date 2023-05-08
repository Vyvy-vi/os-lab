#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int retValue;
  retValue=mkdir(argv[1], S_IRWXU | S_IRWXG);

  if (retValue == -1)
    printf("ERROR");

  return 0;
}
