#include <iostream>

struct point2d {
	int x;
	int y;

	point2d() : x{0}, y{0} { }

	// Az üres konstruktor nem fut le magától.
	// A delegáltnak szánt konstruktort meghívását nem szabad kifelejteni.
    point2d(void *f) {
		// x és y értéke így nem definiált
		std::cout << x << ' ' << y << '\n';
	}
};

int main() {
	point2d p(nullptr);
	return 0;
}
