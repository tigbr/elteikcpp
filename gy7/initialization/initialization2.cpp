#include <iostream>

// https://en.cppreference.com/w/cpp/language/explicit.html

struct point2d {
	int x;
	int y;

#if 1
	point2d(int x) { }
#else
	// int nem konvertálódhat implicit-ül point2d-re
	explicit point2d(int x) { }
#endif
};

void foo(point2d p) { }

std::ostream& operator<<(std::ostream &os, point2d p) {
	os << p.x << ", " << p.y << '\n';
	return os;
}

int main() {
	int n = 1007;
	foo(n); // Nem fordul-le, ha a point2d::point2d(int) konstruktor explicit
	return 0;
}
