#include <iostream>

// Az alábbi két kapcsoló olvashatóbbá teheti a hibaüzeneteket:
// -Wfatal-errors -fcompare-debug-second
int main(void) {
	int x;
	std::cin >> x >> '\n';
	std::cout << x * 2 << '\n';
	return 0;
}
