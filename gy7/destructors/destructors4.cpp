#include <stdio.h>

struct TestCD {
	const char *message;

	TestCD(const char *msg) : message{msg} {
		printf("Constructor %s\n", message);
	}

	~TestCD() {
		printf("Destructor %s\n", message);
	}
};

int main(int argc, char **argv) {
	TestCD main_scope("main_scope");
	TestCD("temporal");

    // A referencia meghosszabbítja a temporális élettartamát.
	const auto& t = TestCD("main_ref_temporal");

	if (argc < 2) {
		return 0;
	}

	TestCD other("other");

	return 0;
}
