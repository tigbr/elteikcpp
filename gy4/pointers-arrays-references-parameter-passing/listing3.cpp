#include <iostream>

int* foo() {
	// Az "a" változó területe újra lefoglalhatóvá válik a függvény visszatérése után.
	// A visszaadott pointer nem egy élő objektumra fog mutatni.
	// Ez a program így nem definiált viselkedést tartalmaz, javítani kell.
	int a = 32;
	return &a;
}

void bar() {
	int b = 48;
}

// Különböző fordítókkal különböző viselkedést eredményezhet ez a program.
int main() {
	int *ptr = foo();
	std::cout << *ptr << '\n';
	bar();
	std::cout << *ptr << '\n';
	return 0;
}
