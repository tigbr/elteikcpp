#include <iostream>

int main() {

	int numbers[5]; // öt darab int folytonosan egymás mellett tárolva
	
	int *ptr_to_int = numbers;          // ptr_to_numbers a numbers tömb első elemének címét
	int (&ref_to_numbers)[5] = numbers; // ref_to_numbers referencia egy öt darab int-ből álló tömbre
	int (*ptr_to_array)[5] = &numbers;

	std::cout << sizeof(numbers) << '\n';
	std::cout << sizeof(*numbers) << '\n';
	std::cout << sizeof(ref_to_numbers) << '\n';
	std::cout << sizeof(*ptr_to_array) << '\n';

	std::cout << sizeof(&numbers) << '\n';
	std::cout << sizeof(ptr_to_int) << '\n';

	return 0;
}
