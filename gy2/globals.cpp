#include <stdio.h>

int return_4() {
	return 4;
}

int x = return_4();

int main() {
	printf("%d\n", x);
	return 0;
}
