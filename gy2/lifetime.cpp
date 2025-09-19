#include <iostream>

int global = 0;

int global_variable() {
	global += 1;
	return global;
}

int static_variable() {
	static int x = 0;
	x += 1;
	return x;
}

int automatic_variable() {
	int x = 0;
	x += 1;
	return x;
}

int main(void) {

	for (int i = 0; i < 5; i += 1) {
		std::cout << automatic_variable() << '\n';
	}

	std::cout << '\n';

	for (int i = 0; i < 5; i += 1) {
		std::cout << static_variable() << '\n';
	}

	for (int i = 0; i < 5; i += 1) {
		std::cout << global_variable() << '\n';
	}

	return x;
}
