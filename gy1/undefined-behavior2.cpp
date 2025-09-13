// Ha az 'a' változó értéke kisebb, mint az int típusban tárolható
// legnagyobb érték, akkor a + 1 > 0 mindig igaz lesz.
// Amikor pedig az 'a' változó értéke INT_MAX, akkor nem definiált az a + 1 érték, így
// a + 1 > 0 sem, ami ugye az elágazás feltétele is egyben.
// Emiatt dönthet úgy a fordító, hogy igaznak tekinti ezt esetet is és akkor kitörölheti
// a feltételvizsgálatot a hamis ághoz tartozó kódrészletettel együtt.
//
// A szabvány nem mondta meg, hogy ilyenkor minek kell történni, emiatt bármit is csinál
// ezzel az esettel a fordító, azzal nem fogja megszegni a szabványt.
int f(int a) {
	if (a + 1 > a)
		return 1;
	return 42;
}

// unsigned int esetén már definiálva van a túlcsordulás.
// Olyankor átvált a legkisebb értékre, így hamis is lehet
// az elágazás feltétele, ezért azt az ágat nem lehet kioptimalizálni.
//
// Ennél a kódnál van előírása a szabványnak, amit kötelessége
// követni a fordítónak.
unsigned int g(unsigned int a) {
	if (a + 1 > a)
		return 1;
	return 42;
}
