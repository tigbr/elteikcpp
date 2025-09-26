#include <iostream>

enum class shape_type {
	circle,
	rectangle
};

struct circle {
	float radius;
};

struct rectangle {
	float width;
	float height;
};

struct shape {
	shape_type type;
	shape () {
		std::cout << "Shape created!" << '\n';
	}

	shape (const shape &s) {
		std::cout << "Shape copied!" << '\n';
	}

	union {
		struct circle c;
		struct rectangle r;
	} data;
};

float area(shape *s) {
	switch (s->type) {
		case shape_type::circle: {
			return s->data.c.radius * s->data.c.radius * 3.14159f;
		} break;
		case shape_type::rectangle: {
			return s->data.r.width * s->data.r.height;
		} break;
	}
	return 0.0f;
}

float area(shape s) {
	switch (s.type) {
		case shape_type::circle: {
			return s.data.c.radius * s.data.c.radius * 3.14159f;
		} break;
		case shape_type::rectangle: {
			return s.data.r.width * s.data.r.height;
		} break;
	}
	return 0.0f;
}

int main() {
	shape s;
	area(&s);
	area(s);
	return 0;
}
