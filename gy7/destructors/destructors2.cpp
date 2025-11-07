#include <iostream>

// https://en.cppreference.com/w/cpp/language/new.html
// https://en.cppreference.com/w/cpp/language/delete.html

int main(void) {
	int count;
	std::cin >> count;
	int *numbers = new int[count];
	if (numbers != nullptr) {
		for (int i = 0; i < count; i += 1) {
			std::cin >> numbers[i];
		}
		std::cout << "Numbers in reverse: \n";
		for (int i = count-1; 0 <= i; i -= 1) {
			std::cout << numbers[i] << '\n';
		}
		delete[] numbers;
	}
	return 0;
}
