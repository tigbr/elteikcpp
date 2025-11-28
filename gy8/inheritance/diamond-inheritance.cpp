#include <iostream>

struct A { int x; };
struct B : public A { };
struct C : public A { };
struct D : public C, public B { };

// struct E : public A, public A { };

int main() {
	D d;
	d.B::x = 3;
	d.C::x = 5;
	std::cout << "d.B::x " << d.B::x << ' ' << &d.B::x << '\n';
	std::cout << "d.C::x " << d.C::x << ' ' << &d.C::x << '\n';
	D *dptr;
	// A is ambiguous base of 'D'
	// A *aptr = dptr;
	D &dref = d;
	// A is ambiguous base of 'D'
	// A &aref = dref;
	return 0;
}
