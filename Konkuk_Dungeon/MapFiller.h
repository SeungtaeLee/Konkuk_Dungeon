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
		//¸Ê µ¤¾î¾²±â
		for (int i = 0; i < MAP_AREA_ROWS; i++) {
			memcpy_s(screen->map[i], sizeof(screen->map[i]), cur_floor->map[i], sizeof(cur_floor->map[i]));
		}
		//¾ÆÀÌÅÛ µ¤¾î¾²±â
		for (auto item : cur_floor->items)
		{
			screen->map[item.x_pos][item.y_pos] = item.symbol;
		}
		//¸ó½ºÅÍ µ¤¾î¾²±â
		for (auto monster : cur_floor->monsters)
		{
			screen->map[monster.x_pos][monster.y_pos] = monster.symbol;
		}
		//Ä³¸¯ÅÍ µ¤¾î¾²±â
		screen->map[character->x_pos][character->y_pos] = character->symbol;
	}
};