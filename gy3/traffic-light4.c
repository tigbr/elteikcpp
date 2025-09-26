typedef enum {
	traffic_light_state_red,
	traffic_light_state_red_yellow,
	traffic_light_state_green,
	traffic_light_state_yellow,
} traffic_light_state;

enum color {
	red,
	green,
	yellow,
};

typedef struct {
	traffic_light_state state;
} traffic_light;

void traffic_light_default_initialize(traffic_light *light) {
	light->state = traffic_light_state_red;
}

int traffic_light_set(traffic_light *light, traffic_light_state state) {
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

void traffic_light_switch_to_next_state(traffic_light *light) {
	traffic_light_state new_state;
	switch (light->state) {
		case traffic_light_state_red:        new_state = traffic_light_state_red_yellow; break;
		case traffic_light_state_red_yellow: new_state = traffic_light_state_green; break;
		case traffic_light_state_green:      new_state = traffic_light_state_yellow; break;
		case traffic_light_state_yellow:     new_state = traffic_light_state_red; break;
	}
	light->state = new_state;
}

int main(void) {
	traffic_light light;
	traffic_light_set(&light, traffic_light_state_red);
	return 0;
}
