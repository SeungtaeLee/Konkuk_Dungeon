#pragma once

#include "Filler.h"
#include "Building.h"
#include "Character.h"

class MapFiller : public Filler{
public:
	Character* character;
	Building* building;

	MapFiller(
		Screen *screen, 
		int x_start, 
		int x_end, 
		int y_start, 
		int y_end, 
		Character* character, 
		Building* building
	)
		:Filler(screen, x_start, x_end, y_start, y_end)
	{
		this->character = character;
		this->building = building;
	}

	void fill() {

	}
	
};