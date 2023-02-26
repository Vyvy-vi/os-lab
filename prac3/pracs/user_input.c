#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
  char buffer[1];
  int cap = 1000;
  int size = 0;
  char* str = (char *) malloc(cap);

  read(0, buffer, 1);

  while (buffer[0] != '$') {
    if (size >= cap) {
      cap += 500;
      str = realloc(str, cap);
    } else {
      str[size] = buffer[0];
      read(0, buffer, 1);
      size++;
    }
  }
  write(1, str, size);
  write(1, "\n", 1);
  
  free(str);
}
