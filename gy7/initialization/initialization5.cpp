#include <iostream>
#include <vector>

// név nélküli értékek létrehozásánál különböző szintaxist lehet használni
std::vector<int> bar() {
	return std::vector<int>();
}

std::vector<int> foo() {
#if 1
	return std::vector<int>{};
#else
	return {};
#endif
}

std::vector<int> foo(int i) {
	return {i, 123, 0434, 3123};
}

int main() {
	std::vector<int> numbers{4325};
	std::cout << bar().size() << '\n';
	std::cout << foo().size() << '\n';
	std::cout << foo(4325).size() << '\n';
	std::cout << foo(4325)[0] << '\n';
	std::cout << numbers.size() << '\n';
	std::cout << numbers[0] << '\n';
	return 0;
}
