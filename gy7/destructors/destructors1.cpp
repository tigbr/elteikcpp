#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int count;
	scanf("%d", &count);
	int *numbers = (int*) malloc(count * sizeof(*numbers));
	if (numbers != nullptr) {
		for (int i = 0; i < count; i += 1) {
			scanf("%d", numbers+i);
		}
		puts("Numbers in reverse:");
		for (int i = count-1; 0 <= i; i -= 1) {
			printf("%d\n", numbers[i]);
		}
		free(numbers);
	}
	return 0;
}
