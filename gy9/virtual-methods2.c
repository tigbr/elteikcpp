#include <stdlib.h>
#include <stdio.h>

const float pi = 3.14159f;

struct shape_virtual_table {
	float (*get_area)(const void*);
	float (*get_circumference)(const void*);
};

struct shape {
	struct shape_virtual_table *vtable;
};

/* -------------------------------------------------------------------------- */

struct circle {
	const struct shape_virtual_table *vtable;
	float radius;
};

float circle_get_area(const void *object) {
	const struct circle *c = object;
	return c->radius * c->radius * pi;
}

float circle_get_circumference(const void *object) {
	const struct circle *c = object;
	return c->radius * c->radius * pi;
}

const struct shape_virtual_table circle_vtable = {
	circle_get_area,
	circle_get_circumference
};

struct circle* create_circle(float radius) {
	struct circle *result = malloc(sizeof(*result));
	if (result != NULL) {
		result->vtable = &circle_vtable;
		result->radius = radius;
	}
	return result;
}

/* -------------------------------------------------------------------------- */

struct rectangle {
	const struct shape_virtual_table *vtable;
	float width;
	float height;
};

float rectangle_get_area(const void *object) {
	const struct rectangle *r = object;
	return r->width * r->height;
}

float rectangle_get_circumference(const void *object) {
	const struct rectangle *r = object;
	return 2 * (r->width + r->height);
}

const struct shape_virtual_table rectangle_vtable = {
	rectangle_get_area,
	rectangle_get_circumference
};

struct rectangle* create_rectangle(float width, float height) {
	struct rectangle *result = malloc(sizeof(*result));
	if (result != NULL) {
		result->vtable = &rectangle_vtable;
		result->width = width;
		result->height = height;
	}
	return result;
}

int main(void) {
	struct shape* shapes[5];
	shapes[0] = (struct shape*) create_circle(2);
	shapes[1] = (struct shape*) create_rectangle(4, 5);
	shapes[2] = (struct shape*) create_rectangle(2, 3);
	shapes[3] = (struct shape*) create_circle(6);
	shapes[4] = (struct shape*) create_rectangle(0.1, 34);
	for (int i = 0; i < 5; i += 1) {
		if (shapes[i] != NULL) {
			printf("Shape area:          %f\n", shapes[i]->vtable->get_area(shapes[i]));
			printf("Shape circumference: %f\n", shapes[i]->vtable->get_circumference(shapes[i]));
			printf("\n");
			free(shapes[i]);
		}
	}
	return 0;
}
