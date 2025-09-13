// #include <iostream>

#ifdef HELP_ME_DEBUG
#define DEBUG_MESSAGE "DEBUG MESSAGE: "
#define DEBUG_PRINT(expr) std::cerr << DEBUG_MESSAGE << #expr " is " << expr << "\n"
#else
#define DEBUG_PRINT(expr)
#endif

int main(int argc, char **argv) {
	DEBUG_PRINT(argc);
	DEBUG_PRINT(argv);
	return 0;
}
