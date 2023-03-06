#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char * argv[]) {

	if (argc < 2) {
		printf("Error: Directory name not provided\n");
		return 1;
	}

	DIR *dp;
	struct dirent *dptr;

	char buff[1000] = "~/Desktop/";

	size_t i = 0;
	size_t argv_size = strlen(argv[1]);
	for (i = 0; i < argv_size; i++) {
		buff[10+i] = argv[1][i]; 
	}
	buff[i] = '\n';
	mkdir(buff, 0777);
	dp = opendir(buff);


	//while ((dptr  = readdir(dp)) != NULL) {
	//	printf("%s (%d) %lld\n", dptr->d_name, dptr->d_type, dptr->d_ino);
	//}

}
