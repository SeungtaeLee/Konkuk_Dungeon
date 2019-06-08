#pragma once

#include "Filler.h"
#include "Condition.h"
#include "Character.h"
using namespace std;

class MapInfoFiller : public Filler {
public:
	Character *character;
	Condition *condition;
	MapInfoFiller(
		Screen *screen,
		int x_start,
		int y_start,
		int x_end,
		int y_end,
		Character *character,
		Condition *condition
	)
		:Filler(screen, x_start, y_start, x_end, y_end)
	{
		this->character = character;
		this->condition = condition;
	}
	void fill() {
		///표시할 정보
		//현재층
		sprintf_s(screen->info_area[0], "현재층 : %d\0", character->floor_at + 1);
		//남은 count 수
		sprintf_s(screen->info_area[1], "남은 카운트 : %d\0", condition->count);
	}
};