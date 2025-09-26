struct traffic_light {
	int state;
};

void traffic_light_default_initialize(struct traffic_light *light) {
	light->state = 0;
}

int traffic_light_set(struct traffic_light *light, int state) {
	if (0 <= state && state <= 3) {
		light->state = state;
		return 0;
	}
	return 1;
}

void traffic_light_switch_to_next_state(struct traffic_light *light) {
	switch (light->state) {
		case 0: light->state = 1; break;
		case 1: light->state = 2; break;
		case 2: light->state = 3; break;
		case 3: light->state = 0; break;
	}
}

void traffic_light_switch_to_next_state2(struct traffic_light *light) {
	light->state += 1;
	if (light->state == 3) light->state = 4;
}

int main(void) {
	struct traffic_light light;
	traffic_light_set(&light, 0);
	return 0;
}
