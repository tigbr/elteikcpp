#include <iostream>

int z = 4321;

struct point2d {
	static int z;
	int x;
	int y;
};

// Linkelési hiba különben
int point2d::z = 0;

int main() {
	// z nem adattagja a point2d objektumoknak 
	point2d p;
	std::cout << sizeof(p) << '\n'; // point2d mérete 

	// Az osztályszintű változó az osztály névterében található
	std::cout << &z << '\n';
	std::cout << &p.z << '\n';
	std::cout << &point2d::z << '\n';
	return 0;
}
