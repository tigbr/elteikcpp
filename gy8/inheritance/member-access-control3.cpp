
struct A {
	int x;
	void foo() { }
private:
	int y;
};

// B ugyanazzal a láthatósággal örökli az x-et és foo-t, mint ahogyan azok az A-ban szerepelnek. Mivel A-ban public x és foo, ezért B-ben is elérhető lesz, illetve B-n kívülről is.
struct B : public A {
	void bar() {
		x = 5;
		foo();
	}
};

// C protectedként örökölte az A-beli x-et és foo-t, ezért C-ben hozzá lehet férni, de C-n kívülről már nem
struct C : protected A {
	void bar() {
		x = 5;
		foo();
	}
};

// D privátként örökölte az A-beli x-et és foo-t. Ekkor D-ből hozzá lehet férni x-hez és foo-hoz, de D-n kívülről nem, illetve a D-ből öröklő osztályokból sem.
struct D : private A {
	void foobar() {
		x = 5;
		foo();
	}
};

struct E : public D {
	void foobar() {
		x = 5;
		foo();
	}
};

int main() {

	B b;
	b.x = 5;
	b.foo();

	return 0;
}

