#include <iostream>

void f() {
	// Fordítási hiba: Itt még nem volt 'x' deklarálva
	// std::cout << x << '\n';
}

int x = 0;

void g() {
	// A globális x értéke lesz kiírva
	std::cout << x << '\n';
}

int main(void) {
	std::cout << x << '\n';

	int x = 1;
	{
		std::cout << x << '\n';

		int x = 2;
		std::cout << x << '\n';
		std::cout << ::x << '\n';
		g();
	}
	return 0;
}
