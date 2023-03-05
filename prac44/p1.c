#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int dd;
    struct dirent *dptr;
    DIR *dp;

    if (argc < 2)
    {
        printf("ERROR: Directory name not provided.\n");
        return 1;
    }

    dd = mkdir(argv[1], S_IRWXU | S_IRWXO);

    dp = opendir(argv[1]);

    if (dp == NULL && dd == -1)
    {
        printf("Can't create or open directory with name: %s\n", argv[1]);
        return 1;
    }

    write(1, "Enter filename: ", 17);

    char name_buff[50];
    int name_len = read(0, name_buff, 50);

    write(1, "Enter content: ", 16);

    char content_buff[1000];
    int read_bytes = read(0, content_buff, 1000);

    int dir_name_len = strlen(argv[1]);
    char filename[(dir_name_len + 1 + name_len)];
    strcpy(filename, argv[1]);
    filename[dir_name_len] = '/';
    strcat(filename, name_buff);
    filename[dir_name_len + name_len] = '\0';

    int fd = open(filename, O_CREAT | O_WRONLY, 0777);
    write(fd, content_buff, read_bytes);

    closedir(dp);
    dp = opendir(argv[1]);

    printf("Contents of directory %s\n", argv[1]);
    while (NULL != (dptr = readdir(dp)))
    {
        printf("%s %d\n", dptr->d_name, dptr->d_type);
    }
}