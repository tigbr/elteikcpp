template <typename T>
struct my_unique_ptr {
	T *ptr;

	my_unique_ptr(T *t) : ptr{t} { }

	~my_unique_ptr() {
		if (ptr) {
			delete ptr;
		}
	}
};

int main() {
	return 0;
}
