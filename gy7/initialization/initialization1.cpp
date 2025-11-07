#include <iostream>
#include <initializer_list> // C++11

#if 0
// https://en.cppreference.com/w/cpp/language/initialization.html
std::string s1;           // default-initialization
std::string s2();         // NOT an initialization!
                          // actually declares a function “s2”
                          // with no parameter and returns std::string
std::string s3 = "hello"; // copy-initialization
std::string s4("hello");  // direct-initialization
std::string s5{'a'};      // list-initialization (since C++11)

char a[3] = {'a', 'b'}; // aggregate initialization
                        // (part of list initialization since C++11)
char& c = a[0];         // reference initialization
#endif

struct point2d {
	int x;
	int y;

	point2d()                     { puts("default constructor"); }
	point2d(const point2d &other) { puts("copy constructor"); }
	point2d(point2d&& other)      { puts("move constructor"); }
	point2d(int x, int y)         { puts("point2d(int x, int y) constructor"); }

	// C++11-től
	// Ha definiálva van, akkor az int típusú elemeket tartalmazó { }-es inicializálás ezt fogja hívni.
	point2d(std::initializer_list<int> x) { puts("point2d(std::initializer_list<int> x) constructor"); }
};

std::ostream& operator<<(std::ostream &os, point2d p) {
	os << p.x << ", " << p.y << '\n';
	return os;
}

int main() {
	// A default konstruktor meghívásához nem kell zárójelet írni.
	point2d p1;
	// point2d v(); // Most vexing parse

	// C-szerű brace initialization, ha nincsen semmilyen konstruktor kézzel megadva.
	// Ha már van bármilyen kézzel megadott konstruktor, akkor ekvivalens a gömbölyűzárójeles szintaxissal.
	// Ha van std::initializer_list-et váró konstruktor, akkor a {}-es szintaxis azt részesíti előnyben.
	point2d p2{1, 2};

	return 0;
}

