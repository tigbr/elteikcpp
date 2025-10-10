#include <iostream>

// Rengeteg példa alapértelmezet bemenetértékekre valódi könyvtárban: (SliderFloat, DragFloat, InputTextWithHint  stb.)
// https://github.com/ocornut/imgui/blob/master/imgui.h

void print(const char *msg, const char *suffix = "\n", unsigned how_many_times = 1) {
	for (unsigned i = 0; i < how_many_times; i += 1) {
		std::cout << msg << suffix;
	}
}

int main(void) {
	print("Hello, world!");
	print("Hello, world!", " (main)\n");
	print("y", "\n", 3);

    // Ha egy későbbi alapértelmezet értékkel rendelkező paramétert konkrétan megadunk,
    // akkor az összes korábbi alapértelmezet értékkel rendelkező paramétert is meg kell adni.
	// print("y",, 3);
	return 0;
}

// Egy alapértelmezet értékkel rendelkező paraméter után már szintén csak alapértelmezet értékkel rendelkező paraméter következhet.
// void foo(int a, int b = 523, int c) { }
