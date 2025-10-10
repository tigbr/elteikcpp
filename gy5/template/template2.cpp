#include <iostream>

// Bár most csak int és float típusokkal használjuk a print-et,
// amelyeknek kis költségű a másolása. Más típusoknál viszont
// mindenképp kerülni szeretnénk a másolást. Ez elérhető
// referencia használatával.
template <typename T>
void print(T &a) {
    std::cout << a << '\n';
}

int main() {
    int i = 102;
    float f = 2.78425;

	// A fordítóprogram létrehozza majd a háttérben print-nek
	// az int-tel, illetve float-tal működő változatát.
	// Sablonfüggvény példányosítható közvetlenül is
    print<int>(i);
    print<float>(f);

	// vagy a fordítóra is bízhatjuk a kikövetkeztetését
	print(i);
	print(f);
    return 0;
}
