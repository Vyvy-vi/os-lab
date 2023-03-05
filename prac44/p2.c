#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    struct dirent *dptr;
    DIR *dp1, *dp2;

    if (argc < 3)
    {
        printf("ERROR: Source Directory name or Destination Directory name not provided.\n");
        printf("Usage: ./a.out SRC_DIR DEST_DIR\n");
        return 1;
    }

    dp1 = opendir(argv[1]);
    int dd = mkdir(argv[2], 0777);
    dp2 = opendir(argv[2]);

    if (dp1 == NULL)
    {
        printf("Can't open directory with name: %s\n", argv[1]);
        return 1;
    }
    if (dp2 == NULL && dd == -1)
    {
        printf("Can't open directory with name: %s\n", argv[2]);
        return 1;
    }

    int old_dir_name_len = strlen(argv[1]);
    char old_filename[1000];
    strcpy(old_filename, argv[1]);
    old_filename[old_dir_name_len] = '/';

    int new_dir_name_len = strlen(argv[1]);
    char new_filename[1000];
    strcpy(new_filename, argv[2]);
    new_filename[new_dir_name_len] = '/';

    while (NULL != (dptr = readdir(dp1)))
    {
        if (dptr->d_type != 8)
            continue;
        for (int i = 0; i < dptr->d_namlen; i++)
        {
            old_filename[old_dir_name_len + 1 + i] = dptr->d_name[i];
            new_filename[new_dir_name_len + 1 + i] = dptr->d_name[i];
        }
        old_filename[old_dir_name_len + 1 + dptr->d_namlen] = '\0';
        new_filename[new_dir_name_len + 1 + dptr->d_namlen] = '\0';

        printf("Copying %s to %s\n", old_filename, new_filename);

        int fd1 = open(old_filename, O_RDONLY);
        int fd2 = open(new_filename, O_CREAT | O_WRONLY, 0777);

        int n;
        char buff[20];
        while ((n = read(fd1, buff, 15)) != 0)
        {
            write(fd2, buff, n);
        }
    }
}