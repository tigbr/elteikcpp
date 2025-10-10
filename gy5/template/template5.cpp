#include <iostream>

template <typename T, int N>
int array_length(T (&array)[N]) {
	return N;
}

int main() {
	int number[5];
	std::cout << array_length(number) << '\n';
	return 0;
}
