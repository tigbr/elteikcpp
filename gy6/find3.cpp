#include <iostream>

bool is_int_even(int x) {
	return x % 2 == 0;
}

bool find(int *numbers, int count, bool condition(int), int &out_result) {
	for (int i = 0; i < count; i += 1) {
		if (condition(numbers[i])) {
			out_result = numbers[i];
			return true;
		}
	}
	return false;
}

int main() {
	int numbers[] = { 1, 1, 2, 3, 4, 5 };
	int count = sizeof(numbers) / sizeof(*numbers);

	int result;
	if (find(numbers, count, is_int_even, result)) {
		std::cout << "Found result: " << result << "\n";
	} else {
		std::cout << "No result found!\n";
	}

	return 0;
}
