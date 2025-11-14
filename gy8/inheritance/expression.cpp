#include <iostream>

struct Expr {
	virtual double get_value() = 0;
};

struct Add : public Expr {
	Expr *left;
	Expr *right;
	virtual double get_value() override {
		return left->get_value() + right->get_value();
	}
};

struct Sub : public Expr {
	Expr *left;
	Expr *right;
	virtual double get_value() {
		return left->get_value() - right->get_value();
	}
};

struct Mul : public Expr {
	Expr *left;
	Expr *right;
	virtual double get_value() {
		return left->get_value() * right->get_value();
	}
};

struct Div : public Expr {
	Expr *left;
	Expr *right;
	virtual double get_value() {
		return left->get_value() / right->get_value();
	}
};

struct Literal : public Expr {
	double value;
	virtual double get_value() {
		return value;
	}
};

#if 0
    +
   / \
  *   4
 / \
5   6
#endif

int main() {
	Literal literals[3];
	literals[0].value = 5;
	literals[1].value = 6;
	literals[2].value = 4;

	Mul mul;
	mul.left = &literals[0];
	mul.right = &literals[1];

	Add add;
	add.left = &mul;
	add.right = &literals[2];

	Expr *e = &add;
	std::cout << e->get_value() << '\n';

	return 0;
}
