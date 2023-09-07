#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
  DIR* d;
  struct dirent* direntPt;

  d = opendir(argv[1]);
  if (d == NULL) {
    printf("dir not found");
    return 2;
  }

  int cnt;
  while ((direntPt = readdir(d)) != NULL) {
    printf("%s - %s\n", direntPt->d_name, ((direntPt->d_type == 4) ? "directory":"file"));
    cnt++;
  }

  printf("Files and directory in Directory - %d\n", cnt);
  closedir(d);
}
