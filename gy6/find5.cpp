#include <iostream>

template <typename T, typename Condition>
T* find(T *it, T *end, Condition condition) {
	while (it != end) {
		if (condition(*it)) {
			return it;
		}
		it++;
	}
	return end;
}

int main() {

	//                0  1  2  3  4  5  6
	int numbers[] = { 0, 1, 2, 3, 4, 5 };
	int count = sizeof(numbers) / sizeof(*numbers);
	int *it = &numbers[0];
	int *end = &numbers[count];

	int matches_so_far = 0;
	int n = 3;
	auto condition = [&matches_so_far, n](int x) {
		if (x % 2 == 0) { 
			matches_so_far += 1;
			if (matches_so_far == n) {
				return true;
			}
		}
		return false;
	};

	int *result = find(it, end, condition);
	if (result != end) {
		std::cout << "Found result: " << *result << "\n";
	} else {
		std::cout << "No result found!\n";
	}
	return 0;
}
