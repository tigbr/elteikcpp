// Az struct és unió típusok adattagjai, metótudsai publikusak alapértelmezésként, míg az osztályok esetében privátak

struct S {
	int x;
	void foo() { }
};

union U {
	int x;
	void foo() { }
};

class C {
	int x;
	void foo() { }
};

int main() {

	S s;
	s.x = 5;
	s.foo();

	U u;
	u.x = 5;
	u.foo();

	C c;
	c.x = 5;
	c.foo();

	return 0;
}

