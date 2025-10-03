#include <iostream>

void intro() {
	int var; // egy db előjeles egész szám
	&var;    // var memóriacíme

	int *ptr1 = &var;             // ptr1 egy int memóriacímét képes tárolni.
                                  // A címképző művelettel lekérdezhető
	ptr1;                         // A ptr1-ben tárolt memóriacím.
	*ptr1;                        // A ptr1-ben tárolt memóriacímen található int értéke.

	const int *ptr2 = &var;       // ptr2 egy írásvédett int memóriacímét tárolja
	int * const ptr3 = &var;      // ptr3 írásvédett és egy int memóriacímét tárolja
	const int *const ptr4 = &var; // ptr4 írásvédett és egy írásvédett int memóriacímét tárolja

	int &ref = var;        // Referencia, ami a var változóra hivatkozik.
	const int &cref = var; // Referencia, ami a var változóra hivatkozik és azt nem engedi megváltoztatni.
    // int &ref2; // Maga a referencia írásvédett, tehát mindig inicializálni kell.
 	// int & const ref2; // Kézzel nem is lehet megadni az írásvédettséget, 

	ref; // A var-ban eltárolt érték.
         // A referenciáknál nincsen külön dereferálási lépés, mint a mutatók esetében.
	&ref; // A var (referencia által hivatkozott) változó címe!
}

int main() {
	return 0;
}
