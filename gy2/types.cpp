#include <iostream>

char c;
short s;
int i;
long l;

float f;
double d;
long double ld;

/*

Előjel nélküli egészek
000 |  0 | 0*4 + 0*2 + 0*1
001 |  1 | 0*4 + 0*2 + 1*1
010 |  2 | 0*4 + 1*2 + 0*1
011 |  3 | 0*4 + 1*2 + 1*1
100 |  4 | 1*4 + 0*2 + 0*1
101 |  5 | 1*4 + 0*2 + 1*1
110 |  6 | 1*4 + 1*2 + 0*1
111 |  7 | 1*4 + 1*2 + 1*1

Egyes komplemens: legnagyobb helyiérték bit-e csak előjel)
000 |  0 |       0*2 + 0*1
001 |  1 |       0*2 + 1*1
010 |  2 |       1*2 + 0*1
011 |  3 |       1*2 + 1*1
100 | -0 | -1* ( 0*2 + 0*1 )
101 | -1 | -1* ( 0*2 + 1*1 )
110 | -2 | -1* ( 1*2 + 0*1 )
111 | -3 | -1* ( 1*2 + 1*1 )

Kettes komplemens: legnagyobb helyiérték negatív értékben van hozzáadva

000 |  0 | 0*(-4) + 0*2 + 0*1
001 |  1 | 0*(-4) + 0*2 + 1*1
010 |  2 | 0*(-4) + 1*2 + 0*1
011 |  3 | 0*(-4) + 1*2 + 1*1
100 | -4 | 1*(-4) + 0*2 + 0*1
101 | -3 | 1*(-4) + 0*2 + 1*1
110 | -2 | 1*(-4) + 1*2 + 0*1
111 | -1 | 1*(-4) + 1*2 + 1*1

*/

void primitive_type_sizes() {
    std::cout << "sizeof(char): " << sizeof(char) << '\n';
    std::cout << "sizeof(short): " << sizeof(short) << '\n';
    std::cout << "sizeof(int): " << sizeof(int) << '\n';
    std::cout << "sizeof(long): " << sizeof(long) << '\n';
    std::cout << "sizeof(float): " << sizeof(float) << '\n';
    std::cout << "sizeof(double): " << sizeof(double) << '\n';
    std::cout << "sizeof(void*): " << sizeof(void*) << '\n';
}

void literals() {
    'C';   // char
    "C++"; // const char *
    5;     // int
    5.;    // double
    5.f;   // float
    5e-4;  // double, értéke 0.0005
    5e-4f; // float, értéke 0.005
    0xFF;  // int 16-os számrendszerben megadva
    012;   // int 8-as számrendszerben megadva
    5l;    // long int
    5u;    // unsigned int
    5ul;   // unsigned long int
}

// Egy fordítási hibát kikényszerítve "lekérdezhető" egy literal típusa.
struct tester { void *ptr; };
void guess_type_of_literal() {
	tester t;
	// t = 5.4;
}

float abs(float x) {
	return x < 0 ? -x : x;
}

void floating_point_inaccuracy() {
	float f = 0.0f;
	for (int i = 0; i < 10; i += 1) {
		f += 0.1f;
	}
	std::cout << f << '\n';
	std::cout << 1.0f << '\n';
	std::cout << (f == 1.0f) << '\n';
	std::cout << (abs(f - 1.0f) < 0.0001) << '\n';
}

int numbers[3] = { 1, 2, 3 };
int numbers2[] = { 1, 2, 3 };

char string1[] = {'H', 'e', 'l', 'l', 'o', ',', 'w', 'o', 'r', 'l', 'd', '!', '\0'};
char string2[] = "Hello, world!";

void character_array_vs_ptr_to_string_literal() {
	// Ez a "Hello, world!" írásvédett tárterületre kerül elhelyezésre. Ha megpróbáljuk felülírni, összeomlik a program
	// A fordító valószínűleg figyelmeztet is bennünket, hogy const char* típusú változót kellene használni.
	// Feladat: Használjuk a debugger-t (pl. gdb), hogy megkeressük a program összeomlási helyét! Próbáljuk meg debug szimbólumok nélkül, valamint azokkal együtt is (-g vagy -ggdb kapcsoló fordításnál)!
	const char *str1 = "Hello, world!";
	// str1[0] = 'h';
	
    // Ez a "Hello, world!" az str2 tömbben kerül elhelyezésre, amit szabad írni.
	char str2[] = "Hello, world!";
	std::cout << str2 << '\n';
	str2[0] = 'h';
	std::cout << str2 << '\n';
}

void const_correctness() {
	int *ptr1;
	const int *ptr2;

	int * const ptr3 = 0;
	const int * const ptr4 = 0;
}

struct mystruct {
	short s;
	float f;
};

union myunion {
	short s;
	float f;
};

struct paddingstruct1 {
	short s1;
	float f;
	short s2;
};

struct paddingstruct2 {
	short s1;
	short s2;
	float f;
};

void structure_size() {
	std::cout << "sizeof(mystruct): " << sizeof(mystruct) << '\n';
	std::cout << "sizeof(myunion): " << sizeof(myunion) << '\n';

	std::cout << '\n';

	mystruct m;
	std::cout << "mystruct member addresses:\n";
	std::cout << &m.s << '\n';
	std::cout << &m.f << '\n';

	std::cout << '\n';

	myunion u;
	std::cout << "myunion member addresses:\n";
	std::cout << &u.s << '\n';
	std::cout << &u.f << '\n';

	std::cout << '\n';

	union {
		paddingstruct1 p1;
		paddingstruct2 p2;
	} paddingtest;
	std::cout << "sizeof(paddingstruct1): " << sizeof(paddingstruct1) << '\n';
	std::cout << "sizeof(paddingstruct2): " << sizeof(paddingstruct2) << '\n';

	std::cout << '\n';

	std::cout << "paddingstruct1 member addresses:\n"; 
	std::cout << (long) paddingtest.p1.s1 << '\n';
	std::cout << (long) paddingtest.p1.f << '\n';
	std::cout << (long) paddingtest.p1.s2 << '\n';

	std::cout << '\n';

	std::cout << "paddingstruct2 member addresses:\n"; 
	std::cout << (long) paddingtest.p2.s1 << '\n';
	std::cout << (long) paddingtest.p2.s2 << '\n';
	std::cout << (long) paddingtest.p2.f << '\n';
}

int main(void) {
	character_array_vs_ptr_to_string_literal();
	return 0;
}
