#include <stdio.h>  // printf
#include <iostream> // std::cout

void io1() {
	int i = 3;

	scanf("%d", &i);
	fscanf(stdin, "%d", &i);

	fprintf(stdout, "%d\n", i);
	fprintf(stderr, "%d\n", i);

	std::cin >> i;
    std::cout << i << '\n';
	std::cerr << i << '\n';
}

void printing_safety() {
	int i = 3;
	printf("%d\n", i);

	std::cout << i << '\n';
    std::cout << i << std::endl;
}

int main(void) {
	return 0;
}
