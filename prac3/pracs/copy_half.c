/*
 * Copy half the content of a file into a newly created file:
 * - a) first half of file
 * - b) second half of file
 */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Please mention filename.\nUsage: ./a.out filename.ext\n");
    return 1;
  }

  int fd = open(argv[1], O_RDONLY);
  int size = lseek(fd, -1, SEEK_END);
  int buff_size = size / 2;
  char buff[buff_size];

  printf(
      "Which half of %s do you want to copy?\na) First Half of file\nb) Second Half of file\nEnter [a/B]: ",
      argv[1]);
  char choice;
  scanf("%c", &choice);

  if (choice == 'a' || choice == 'A')
  {
    lseek(fd, 0, SEEK_SET);
  }
  else
  {
    lseek(fd, buff_size, SEEK_SET);
  }

  read(fd, buff, buff_size);
  fd = open("newfile.txt", O_CREAT | O_WRONLY, 0666);
  write(fd, buff, buff_size);
}
