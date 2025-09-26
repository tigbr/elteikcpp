enum class traffic_light_state {
	red,
	red_yellow,
	green,
	yellow,
};

enum class color {
	red,
	green,
	yellow,
};

struct traffic_light {
	traffic_light_state state;
};

void traffic_light_default_initialize(traffic_light *light) {
	light->state = traffic_light_state::red;
}

bool traffic_light_set(traffic_light *light, traffic_light_state state) {
	if (state == traffic_light_state::red ||
        state == traffic_light_state::red_yellow ||
        state == traffic_light_state::green ||
        state == traffic_light_state::yellow)
    {
		light->state = state;
		return false;
	}
	return true;
}

void traffic_light_switch_to_next_state(traffic_light *light) {
	switch (light->state) {
		case traffic_light_state::red:        light->state = traffic_light_state::red_yellow; break;
		case traffic_light_state::red_yellow: light->state = traffic_light_state::green;      break;
		case traffic_light_state::green:      light->state = traffic_light_state::yellow;     break;
		case traffic_light_state::yellow:     light->state = traffic_light_state::red;        break;
	}
}

int main(void) {
	traffic_light light;
	traffic_light_set(&light, traffic_light_state::red);
	return 0;
}
