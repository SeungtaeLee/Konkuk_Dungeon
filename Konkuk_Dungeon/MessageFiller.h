#pragma once

#include "Filler.h"

class MessageFiller : public Filler {
public:
	string message;
	MessageFiller(Screen *screen, int x_start, int x_end, int y_start, int y_end, string message)
		: Filler(screen, x_start, x_end, y_start, y_end)
	{
		this->message = message;
	}
	void set_message(string new_message) {
		this->message = new_message;
	}
	void fill() {
		memcpy_s(screen->message_area[0], sizeof(screen->message_area[0]), message.c_str(), message.length());
	}
};