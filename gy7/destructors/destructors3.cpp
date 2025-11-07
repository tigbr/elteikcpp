#include <iostream>
#include <memory>

// C++11 óta
// https://en.cppreference.com/w/cpp/memory/unique_ptr.html

int main(void) {
	int count;
	std::cin >> count;
	std::unique_ptr<int[]> numbers{new int[count]};
	if (numbers) {
		for (int i = 0; i < count; i += 1) {
			std::cin >> numbers[i];
		}
		std::cout << "Numbers in reverse: \n";
		for (int i = count-1; 0 <= i; i -= 1) {
			std::cout << numbers[i] << '\n';
		}
	}
	return 0;
}
