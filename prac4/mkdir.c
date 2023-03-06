#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
	int dd;

	if (argc < 2) {
		printf("Error: insufficient arguments\nUsage: ./a.out dirname\n");
		return 1;
	}

	dd =  mkdir(argv[1], S_IRWXU | S_IRWXO);

	if (dd == -1) {
		printf("Error: Can't create directory with name: %s\n", argv[1]);
	} else {
		printf("Directory %s has created\n", argv[1]);
	}
}
