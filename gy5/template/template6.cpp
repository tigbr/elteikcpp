#include <iostream>

// godbolt-ban ellenőrizzük, hogy nem futási időben számoóldik ki!

template <int N>
struct CompileTimeFactorial {
	static const int result = N * CompileTimeFactorial<N-1>::result;
};

template <>
struct CompileTimeFactorial<0> {
	static const int result = 1;
};

int main() {
	std::cout << CompileTimeFactorial<5>::result << '\n';
	return 0;
}
