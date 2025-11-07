#include <vector>
#include <iostream>

struct point2d {
	int x;
	int y;
};

int main() {

	int a;
	int b = 4;
	int c = b;

	// Most vexing parse C++
	// int d(); // Ez így függvénydeklaráció
	int e(4); // Ez már nem függvénydeklaráció
	int f(b);

	int g{};
	int h{4};
	int i{b};

	int j = {};
	int k = {4};
	int l = {b};

	point2d p;
	point2d p2 = {0, 1};
	// point2d p3(0, 0); // Ez már nem függvénydeklaráció, de még nincsen ilyen bemeneteket váró konstruktora point2d-nek.
	point2d p4{0, 0};
	point2d p5 = p2;
	point2d p6(p2);
	point2d p7{p2};

	// Miért más a jelentés?
	std::vector<int> numbers1{100, 1}; // vektor tartalma: 100, 1
	std::vector<int> numbers2(100, 1); // vektor tartalma: 1, 1, 1, 1, 1, ... (100db)

	std::cout << numbers1.size() << '\n';
	std::cout << numbers2.size() << '\n';

	return 0;
}
