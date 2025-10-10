#include <iostream>
#include <vector>
#include <array>

// Lusta kiértékelés / Duck-typing
template <typename T>
void foo(T& t) {
	t.push_back(4);
}

int main() {

	std::vector<int> numbers;
	foo(numbers);
	std::cout << numbers.size() << "\n";
	std::cout << numbers[0] << "\n";

	// Csak akkor kapunk fordítási hibát, ha egy nem megfelelő
	// típussal példányosítjuk a sablont.
	// std::array<int, 5> array;
	// foo(array);

	return 0;
}
