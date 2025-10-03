#include <iostream>

void increment_by_ref(int (&items)[5]) {
	for (int i = 0; i < 5; i += 1) {
		items[i] += 1;
	}
}

void increment_by_ptr(int (*items)[5]) {
	for (int i = 0; i < 5; i += 1) {
		(*items)[i] += 1;
	}
}

void increment(int items[5]) {
	for (int i = 0; i < 5; i += 1) {
		items[i] += 1;
	}
}

int main() {
	int items[5] = { 0, 0, 0, 0, 0 };

	for (int i = 0; i < 5; i += 1) { std::cout << items[i] << ' '; }
	std::cout << '\n';

	return 0;
}
