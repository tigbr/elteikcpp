#include <iostream>

struct point2d {
	int x;
	int y;
};

bool operator==(point2d a, point2d b) {
	return a.x == b.x && a.y == b.y;
}

bool operator==(point2d &a, point2d &b) {
	return a.x == b.x && a.y == b.y;
}

#if 0
// Nem lehet minden paraméter primitív típus
// Azokra már definiálva vannak a műveletek
bool operator==(point2d *a, point2d *b) {
	return a->x == b->x && a->y == b->y;
}
#endif

#if 0
bool operator==(int a, int b) {
	return false;
}
#endif

point2d operator+(point2d a, point2d b) {
	point2d result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return result;
}

point2d operator-(point2d a, point2d b) {
	point2d result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return result;
}

point2d operator*(int scale, point2d p) {
	point2d result;
	result.x = scale * p.x;
	result.y = scale * p.y;
	return result;
}

point2d operator*(point2d p, int scale) {
	return scale * p;
}

int main() {
	point2d p{};
	std::cout << "(" << p.x << " , " << p.y << ")" << "\n";
	return 0;
}

