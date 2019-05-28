#pragma once

#include "Constants.h"
#include <vector>

class Screen{
public:
	vector<vector<char> > screen;

	Screen()
	{
		screen.resize(SCREEN_ROWS);
		for (int i = 0; i < SCREEN_ROWS; i++) {
			screen[i].resize(SCREEN_COLS);
		}
	}

	void print(){

	}
};