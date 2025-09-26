enum traffic_light_state {
	traffic_light_state_red,
	traffic_light_state_red_yellow,
	traffic_light_state_green,
	traffic_light_state_yellow,
};

enum color {
	red,
	green,
	yellow,
};

struct traffic_light {
	enum traffic_light_state state;
};

void traffic_light_default_initialize(struct traffic_light *light) {
	light->state = red;
}

int traffic_light_set(struct traffic_light *light, enum traffic_light_state state) {
	if (state == traffic_light_state_red ||
        state == traffic_light_state_red_yellow ||
        state == traffic_light_state_green ||
        state == traffic_light_state_yellow)
    {
		light->state = state;
		return 0;
	}
	return 1;
}

void traffic_light_switch_to_next_state(struct traffic_light *light) {
	switch (light->state) {
		case traffic_light_state_red:        light->state = traffic_light_state_red_yellow; break;
		case traffic_light_state_red_yellow: light->state = traffic_light_state_green;      break;
		case traffic_light_state_green:      light->state = traffic_light_state_yellow;     break;
		case traffic_light_state_yellow:     light->state = traffic_light_state_red;        break;
	}
}

int main(void) {
	struct traffic_light light;
	traffic_light_set(&light, traffic_light_state_red);
	return 0;
}
