enum traffic_light_state {
	red,
	red_yellow,
	green,
	yellow,
};

struct traffic_light {
	enum traffic_light_state state;
};

void traffic_light_default_initialize(struct traffic_light *light) {
	light->state = red;
}

// Még mindig
int traffic_light_set(struct traffic_light *light, enum traffic_light_state state) {
	if (state == red || state == red_yellow || state == green || state == yellow) {
		light->state = state;
		return 0;
	}
	return 1;
}

void traffic_light_switch_to_next_state(struct traffic_light *light) {
	// A fordító le tudja ellenőrizni, hogy minden enum állandót lefedtünk-e.
	// -Wswitch
	switch (light->state) {
		case red:        light->state = red_yellow; break;
		case red_yellow: light->state = green;      break;
		case green:      light->state = yellow;     break;
		case yellow:     light->state = red;        break;
	}
}

void traffic_light_switch_to_next_state2(struct traffic_light *light) {
	light->state += 1;
	if (light->state == yellow) light->state = red;
}

int main(void) {
	struct traffic_light light;
	traffic_light_set(&light, red);
	return 0;
}
