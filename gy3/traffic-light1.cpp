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

class traffic_light {
	traffic_light_state state;

public:

	traffic_light() {
		this->default_initialize();
	}

	void default_initialize() {
		this->state = traffic_light_state::red;
	}

	traffic_light_state get_current_state() { return this->state; }

	bool set(traffic_light_state state) {
		if (state == traffic_light_state::red ||
			state == traffic_light_state::red_yellow ||
			state == traffic_light_state::green ||
			state == traffic_light_state::yellow)
		{
			this->state = state;
			return false;
		}
		return true;
	}

	void switch_to_next_state() {
		switch (this->state) {
			case traffic_light_state::red:        this->state = traffic_light_state::red_yellow; break;
			case traffic_light_state::red_yellow: this->state = traffic_light_state::green;      break;
			case traffic_light_state::green:      this->state = traffic_light_state::yellow;     break;
			case traffic_light_state::yellow:     this->state = traffic_light_state::red;        break;
		}
	}
};

int main(void) {
	traffic_light light;
	light.set(traffic_light_state::red);
	light.set(432);
	return 0;
}
