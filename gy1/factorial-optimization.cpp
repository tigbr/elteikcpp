int factorial(int a) {
	if (a <= 0) return 1;
	return a * factorial(a - 1);
}

// A fordítóprogram képes rájönni arra, hogy factorial(5) eredménye 120 lesz, így
// a keletkező gépi kódba egyszerűen beégeti a végeredményt.
// g++ factorial-optimization.cpp -O3
int main() {
	return factorial(5);
}
