#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

int main() {
  DIR* dp;
  struct dirent *direntPt;

  dp = opendir("prac2");
 
  if (dp == NULL)
    printf("Error");

  while ((direntPt = readdir(dp)) != NULL) {
    printf("%s\t", direntPt->d_name);
    printf("%llu\n", direntPt->d_ino);
  }
  closedir(dp);
  return 0;
}
