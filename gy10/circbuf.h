#ifndef CIRCBUF_H
#define CIRCBUF_H

template <typename T> 
class circular_buffer {
	T *buffer;
	int current;
	int insert_count;
	int buffer_size;

public:
	circular_buffer(T *buffer, std::size_t size) {
		this->buffer = buffer;
		this->buffer_size = size;
		this->current = 0;
		this->insert_count = 0;
	}

	void insert(T t) {
		if (current == buffer_size) {
			return;
		}
		buffer[current] = t;
		current += 1;
		this->insert_count += 1;
	}

	int size() {
		return this->insert_count;
	}
};

#endif
