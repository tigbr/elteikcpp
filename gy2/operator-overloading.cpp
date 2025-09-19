#include <iostream>

struct point3d {
	int x, y, z;
};

std::ostream& operator<<(std::ostream& os, point3d p) {
	os << "point { " << p.x << " , " << p.y << " , " << p.z << " }";
	return os;
}

std::ostream* operator<<(std::ostream *os, point3d p) {
	*os << "point { " << p.x << " , " << p.y << " , " << p.z << " }";
	return os;
}

bool operator==(point3d a, point3d b) {
	return a.x == b.x && a.y == b.y && a.z == b.z;
}

point3d operator+(point3d a, point3d b) {
	point3d result{a.x + b.x, a.y + b.y, a.z + b.z};
	return result;
}

int main(void) {
	point3d p1 = { 3, 4, 5 };
	point3d p2 = { 3, 4, 5 };

	std::cout << p1 << '\n';
	operator<<(operator<<(std::cout, p1), '\n');

	*(&std::cout << p1) << '\n';
	operator<<(*operator<<(&std::cout, p1), '\n');

	std::cout << (p1 == p2) << '\n';
	std::cout << (p1 + p2) << '\n';

	return 0;
}

