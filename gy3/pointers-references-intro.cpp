#include <iostream>

void bar() {
	int b = 48;
}

int* foo() {
	// Az "a" változó területe újra lefoglalhatóvá válik a függvény visszatérése után.
	// A visszaadott pointer nem egy élő objektumra fog mutatni.
	// Ez a program így nem definiált viselkedést tartalmaz, javítani kell.
	int a = 32;
	return &a;
}

// g++ fordítóval szegmentációs hibát kaptunk, míg clang++-al 32, majd 48 íródott ki.
int main() {
	int *ptr = foo();
	std::cout << *ptr << '\n';
	bar();
	std::cout << *ptr << '\n';
	return 0;
}
