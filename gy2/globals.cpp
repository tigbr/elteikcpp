#include <stdio.h>

int return_4() {
	puts("globalis");
	return 4;
}

int return_5() {
	puts("statikus");
	return 5;
}

int foo() {
	static int x = return_5();
	return x;
}

int x = return_4();

int main() {
	foo();
	return 0;
}
