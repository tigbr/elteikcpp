#include <stdio.h>

// Az i két megváltoztatása nincsen elválasztva szekvenciaponttal (pl. ;-vel)
// így a fordítóra van bízva, hogy milyen sorrendben értékeli ki azokat.
int main() {
	int i = 0;
	printf("%d, %d\n", i++, i++);
	return 0;
}
