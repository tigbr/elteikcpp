
struct A {
public:
	int x;
	void foo() { }

private:
	int y;
	int z;
	void bar() { }

public:
	int w;
	void baz() { }

protected:
	int v;
	void foobar() { }
};

int main() {

	A s;

	// public
	s.x = 5;
	s.foo();

	// private
	s.y = 5;
	s.z = 5;
	s.bar();

	// public
	s.w = 5;
	s.baz();

	// protected
	s.v = 5;
	s.foobar();

	return 0;
}

