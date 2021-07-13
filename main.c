#include <stdio.h>

int main(int argc, char *argv[]) {
	int a;
	if (argc < 2)
		return (0);
	a = (int)argv[1];
	printf("Hello, World!\n");
	return 0;
}
