#include <iostream>

bool is_int_even(int x) {
	return x % 2 == 0;
}

int find_even(int *numbers, int count, bool condition(int)) {
	for (int i = 0; i < count; i += 1) {
		if (condition(numbers[i])) {
			return numbers[i];
		}
	}
	return -1;
}

int main() {
	int numbers[] = { 1, 1, 2, 3, 4, 5 };
	int count = sizeof(numbers) / sizeof(*numbers);
	int result = find_even(numbers, count, is_int_event);
	if (result == -1) {
		std::cout << "No result found!\n";
	} else {
		std::cout << "Found result: " << result << "\n";
	}
	return 0;
}
