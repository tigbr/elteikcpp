struct B;

struct A {
	// A friend segítségével kivételt lehet képezni tetszőlege sosztályok számára a private, illetve protected megszorítás alól
	// A B struktúrán belül innentől kezdve korlátozás nélkül hozzá lehet férni az A osztályban deklarált dolgokhoz
	friend B;
	private:
		int x;
	protected:
		void foo() { }
};

struct B {
	void bar(A &a) {
		a.x = 4;
	}
};

int main() {
	return 0;
}

