#include <iostream>

int find_even(int *numbers, int count) {
	for (int i = 0; i < count; i += 1) {
		if (numbers[i] % 2 == 0) {
			return numbers[i];
		}
	}
	return -1;
}

int main() {
	int numbers[] = { 0, 1, 2, 3, 4, 5 };
	int count = sizeof(numbers) / sizeof(*numbers);
	int result = find_even(numbers, count);
	if (result == -1) {
		std::cout << "No result found!\n";
	} else {
		std::cout << "Found result: " << result << "\n";
	}
	return 0;
}
