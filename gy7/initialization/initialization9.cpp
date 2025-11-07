#include <iostream>

struct point2d {
	int x;
	int y;

	// A member initialization list kifejezések az adattagok deklarációjának sorrendjében fognak lefutni.
	// Emiatt itt x-be egy inicializálatlan érték fog kerülni...
	// -Wall -Wextra fordítási kapcsolók használata segít elkerülni ezt a hibát.
    point2d() : y{0}, x{y} {
		std::cout << x << " " << y << '\n';
	}
};

int main() {
	point2d p;
    return 0;
}
