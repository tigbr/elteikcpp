#define ADD(a, b) a + b
#define MUL(a, b) a * b

int main(void) {
	// A szöveges helyettesítések után egy nagyobb kötési erősségű művelet
	// miatt más lehet a műveleti sorrend, mint amire eredetileg számítottunk.
	// 0 * 1 + 2
	return MUL(0, ADD(1, 2));
	// Ha feltétlenül makrókat kell használnunk, akkor érdemes kézzel zárójelezést
	// alkalmazni, ezzel biztosítva az elvárt műveleti sorrendet. Például:
	// #define ADD(a, b) ((a) + (b))
	// #define MUL(a, b) ((a) * (b))
}
