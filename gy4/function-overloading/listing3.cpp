#include <stdio.h>
#include <stdlib.h>

#if 0
#undef NULL

#if 0
#define NULL ((void*) 0)
#else
#define NULL (0)
#endif

#endif

// A NULL makró meghatározásától függ, hogy melyik függvény hívódik meg.
// Nem mindegyik fordító ad figyelmeztetést erről.
// A nullptr egy erősen típusos megoldással igyekszik NULL-t helyettesíteni.
void foo(void *ptr)  { puts("calling foo(void*)"); }
void foo(int *ptr)   { puts("calling foo(int*)"); }
void foo(long int i) { puts("calling foo(long int i)"); }

int main(void) {
#if 0
	foo(NULL);
#else
	foo(nullptr);
#endif
	return 0;
}
