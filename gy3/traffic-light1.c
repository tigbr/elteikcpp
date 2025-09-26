#define RED        0
#define RED_YELLOW 1
#define GREEN      2
#define YELLOW     3

struct traffic_light {
	int state;
};

void traffic_light_default_initialize(struct traffic_light *light) {
	light->state = RED;
}

int traffic_light_set(struct traffic_light *light, int state) {
	if (state == RED || state == RED_YELLOW || state == GREEN || state == YELLOW) {
		light->state = state;
		return 0;
	}
	return 1;
}

void traffic_light_switch_to_next_state(struct traffic_light *light) {
	switch (light->state) {
		case RED:        light->state = RED_YELLOW; break;
		case RED_YELLOW: light->state = GREEN;      break;
		case GREEN:      light->state = YELLOW;     break;
		case YELLOW:     light->state = RED;        break;
	}
}

void traffic_light_switch_to_next_state2(struct traffic_light *light) {
	light->state += 1;
	if (light->state == YELLOW) light->state = RED;
}

int main(void) {
	struct traffic_light light;
	traffic_light_set(&light, RED);
	return 0;
}
