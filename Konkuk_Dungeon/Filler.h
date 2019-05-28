#pragma once

#include "Screen.h"

class Filler{
public:
	Screen* screen;
	int x_start, x_end, y_start, y_end;

	Filler(Screen* screen, int x_start, int x_end, int y_start, int y_end){
		this->screen = screen;
		this->x_start = x_start;
		this->x_end = x_end;
		this->y_start = y_start;
		this->y_end = y_end;
	}
	virtual void fill() = 0;
};