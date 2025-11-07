#include <iostream>

struct point2d {
	int x;
	int y;

	// Az inicializációs listában meghívható egy másik konstruktor.
	// Ezt C++-ban delegated constructor-nak hívják.
	point2d() : point2d{0, 0} { puts("point2d()"); }
	point2d(int x, int y) : x{x}, y{y} { puts("point2d(int x, int y)"); }
};

int main() {
	point2d p;
	std::cout << p.x << " " << p.y << '\n';
	return 0;
}
