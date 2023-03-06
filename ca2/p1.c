#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void) {
	// a)  dir with my name
	char my_name[] = "vyom";
	int dirname_len = strlen(my_name);
	mkdir(my_name, S_IRWXU | S_IRWXO);

	// b) make hello.txt in the above directory
	char filename[] = "hello.txt";
	int filename_len = strlen(filename);
	char file_path[dirname_len + 1 + filename_len];
	strcpy(file_path, my_name);
	file_path[dirname_len] = '/';
	strcat(file_path, filename);

	printf("Creating file - %s\n", file_path);
	int fd = open(file_path, O_CREAT | O_WRONLY, 0777);

	// c) enter data from keyboard with buffer size 1024 and save to hello.txt
	int buff_size = 1024;
	char buffer[buff_size];
	write(1, "Enter content for file: ", 25);
	int read_bytes = read(0, buffer, buff_size);
	write(fd, buffer, read_bytes);	

	// d) find the size of file
	int size = lseek(fd, -1, SEEK_END);
	printf("Size of file %s is: %d", file_path, size);	
}
