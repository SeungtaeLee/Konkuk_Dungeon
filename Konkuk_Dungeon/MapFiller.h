#pragma once

#include "Filler.h"
#include "Building.h"
#include "Floor.h"
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
		int floor_at = character->floor_at;
		Floor *cur_floor = building->get_floor(floor_at);
		for (int i = 0; i < MAP_AREA_ROWS; i++) {
			memcpy_s(screen->map[i], sizeof(screen->map[i]), cur_floor->map[i], sizeof(cur_floor->map[i]));
		}
	}
};