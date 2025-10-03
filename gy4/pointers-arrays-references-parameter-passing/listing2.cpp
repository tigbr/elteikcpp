#include <iostream>

void increment(int a) {
	a += 1;
}

void increment_through_ptr(int *ptr) {
	(*ptr) += 1;
}

void increment_through_ref(int &ref) {
	ref += 1;
}

int main() {
    int a = 0;
    std::cout << a << '\n';

    increment(a);
    std::cout << a << '\n';

    increment_through_ptr(&a);
    std::cout << a << '\n';

    increment_through_ref(a);
    std::cout << a << '\n';

    return 0;
}
