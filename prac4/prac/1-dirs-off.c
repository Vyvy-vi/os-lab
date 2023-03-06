#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	DIR *dp;
	struct dirent *dptr;
	
	mkdir("desktop", 0777);
	dp = opendir("desktop");

	write(1, "Adding file to directory desktop\n", 34);
	write(1, "Enter filename: ", 17);
	
	char filename[50];
	int n = read(0, filename, 50);
	
	write(1, "Enter content for file (type $ and press enter after done): ", 61);	
	
	char buffer;
	int cap = 1000;
	int size = 0;

	char* str = (char *) malloc(cap);

	read(0, &buffer, 1);
	while (buffer != '$') {
		if (size >= cap) {
			cap += 500;
			str = realloc(str, cap);
		} else {
			str[size] = buffer;
			read(0, &buffer, 1);
			size++;
		}
	}
	char file[59] = "./desktop/";
	size_t i = 0;
	size_t len = strlen(filename);
	for (i = 0; i < len; i++) {
		file[10 + i] = filename[i];
	}
	int fd = open(file, O_CREAT | O_WRONLY, 0777);
	write(fd, str, size);

	while ((dptr  = readdir(dp)) != NULL) {
		printf("%s (%d) %lld\n", dptr->d_name, dptr->d_type, dptr->d_ino);
	}

}
