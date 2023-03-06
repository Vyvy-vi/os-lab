#include <stdio.h>
#include <sys/stat.h>

int main() {
	int dd;
	dd =  mkdir("ABC", S_IRWXU | S_IRWXO);
	printf("Value of dd is %d\n", dd);
}
