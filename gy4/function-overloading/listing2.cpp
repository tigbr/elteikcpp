#include <stdio.h>

void foo(int&) { puts("foo(int&)"); }
void foo(const int&) { puts("foo(const int&)"); }

// Könnyen lehet többértelmű helyzeteket teremteni.
// Mivel itt másolat kerül átadásra, ezért nem megkülönböztető tényező az írásvédettség.
// void foo(int) { puts("foo(int)"); }
// void foo(const int) { puts("foo(const int)"); }

void bar(double, long int) { puts("bar(double, int)"); }
void bar(float, int) { puts("bar(float, long int)"); }

void baz(char c, double, long int) { puts("bar(double, int)"); }
void baz(const char*, float, int) { puts("bar(float, long int)"); }

int main() {
	int x = 3;
	int &ref = x;
	const int &constref = x;

	// Szigorodjon ref const int& re vagy maradjon csak int&?
	// foo(ref);

	// Az írásvédettség nem veszhet el (const correctness), ezért a const int& változat lesz kiválasztva
	foo(constref);

	// A double szűküljön float-ra vagy az int bővüljön long int-re?
	// bar(1.0, 1);

	// Elég egyetlen paraméter, ami egyértelműen meg tudja határozni a kiválasztandó eljárást
	baz('f', 1.5, 7);
	baz("hello", 1.5, 7);

	return 0;
}
