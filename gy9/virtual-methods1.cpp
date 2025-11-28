#include <stdlib.h>
#include <stdio.h>

const float pi = 3.14159f;

struct shape {
	virtual float get_area() = 0;
	virtual float get_circumference() = 0;
};

struct circle : public shape {
	float radius;

	circle(float r) : radius{r} { }

	virtual float get_area() {
		return radius * radius * pi;
	}

	virtual float get_circumference() {
		return radius * radius * pi;
	}
};

struct rectangle : public shape {
	float width;
	float height;

	rectangle(float w, float h) : width{w}, height{h} { }

	virtual float get_area() {
		return width * height;
	}

	virtual float get_circumference() {
		return 2 * (width + height);
	}
};

int main() {
	struct shape* shapes[5];
	shapes[0] = new circle(2.0f);
	shapes[1] = new rectangle(4.0f, 5.0f);
	shapes[2] = new rectangle(2.0f, 3.0f);
	shapes[3] = new circle(6.0f);
	shapes[4] = new rectangle(0.1f, 34.0f);
	for (int i = 0; i < 5; i += 1) {
		if (shapes[i] != nullptr) {
			printf("Shape area:          %f\n", shapes[i]->get_area());
			printf("Shape circumference: %f\n", shapes[i]->get_circumference());
			printf("\n");
			delete shapes[i];
		}
	}
	return 0;
}
