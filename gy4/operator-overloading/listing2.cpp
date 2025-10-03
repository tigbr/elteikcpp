#include <iostream>

struct point2d {
	int x;
	int y;
};

std::ostream& operator<<(std::ostream& os, point2d p) {
	os << "{ " << p.x << " , " << p.y << " }\n";
	return os;
}

std::ostream* operator<<(std::ostream *os, point2d p) {
	*os << p;
	return os;
}

#if 0
std::ostream* operator<<(std::ostream *os, const char *str) {
	*os << str;
	return os;
}
#endif

int main() {
	point2d p{}, p1{}, p2{};
	std::cout << p;
	&std::cout << p << p1 << p2;
	return 0;
}
