#include <iostream>

// Feleslegesen ne ismételjük önmagunkat
void print(int i) {
	std::cout << i << '\n';
}

void print(float i) {
	std::cout << i << '\n';
}

int main() {
    int i = 102;
	print(i);

    float f = 2.78425;
	print(f);

	return 0;
}
