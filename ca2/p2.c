#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
	// a)  dir made from CLI argument
	if (argc  < 2) {
		printf("ERROR: missing arguments\n");
		printf("Usage: ./a.out DIR_NAME");
		return 1;
	}
	
	int dirname_len = strlen(argv[1]);
	mkdir(argv[1], S_IRWXU | S_IRWXO);

	// b) make file read1.txt in the above directory
	char filename[] = "read1.txt";
	int filename_len = strlen(filename);
	char file_path[dirname_len + 1 + filename_len];
	strcpy(file_path, argv[1]);
	file_path[dirname_len] = '/';
	strcat(file_path, filename);

	printf("Creating file - %s\n", file_path);
	int fd = open(file_path, O_CREAT | O_WRONLY, 0777);
	
	// c) copy last 1/3 data from hello.txt into this file
	char path_to_hello_file[] = "vyom/hello.txt";
	int fd2 = open(path_to_hello_file, O_RDONLY);
	int size = lseek(fd2, -1, SEEK_END);
	int index = 2 * size / 3;
	lseek(fd2, index, SEEK_SET);
	
	int buf_size = size / 3;
	char buffer[buf_size];
	read(fd2, buffer, buf_size);
	write(fd, buffer, buf_size);

	// d) Read the contents of this directory 
    	struct dirent *dptr;
    	DIR *dp;

	dp = opendir(argv[1]);
	printf("Contents of directory %s: \n", argv[1]);
	while (NULL != (dptr = readdir(dp))) {
		printf("%s | (type: %d)\n", dptr->d_name, dptr->d_type);
	}
}
