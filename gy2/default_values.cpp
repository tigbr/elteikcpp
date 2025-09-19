#include <iostream>

int global;

int main(void) {
	int local;
	std::cout << "global: " << global << '\n';
	std::cout << "local: "  << local  << '\n';
	return 0;
}
