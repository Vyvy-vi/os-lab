#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char * argv[]) {

	if (argc < 2) {
		printf("Error: Directory name not provided\n");
		return 1;
	}

	DIR *dp;
	struct dirent *dptr;
	dp = opendir(argv[1]);

	if (dp == NULL) {
		printf("Directory %s not found\n", argv[1]);
		return 1;
	}

	while ((dptr  = readdir(dp)) != NULL) {
		printf("%s (%d) %lld\n", dptr->d_name, dptr->d_type, dptr->d_ino);
	}

}
