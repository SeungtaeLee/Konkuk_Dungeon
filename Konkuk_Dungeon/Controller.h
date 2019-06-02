#pragma once

#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "Building.h"
#include "Condition.h"
#include "Screen.h"
#include "MapFiller.h"
#include "MapInfoFiller.h"
#include "MessageFiller.h"
#include "ConditionFiller.h"

class Controller {
public:
	//모델
	Character *character;
	Building *building;
	Condition *condition;
	
	//뷰
	Screen *screen;
	MapFiller *mapFiller;
	MapInfoFiller *mapInfoFiller;
	MessageFiller *messageFiller;
	ConditionFiller *conditionFiller;
	

	Controller() {
		if (DEBUG_MODE)
			cout << "initiating models" << endl;
		init();
		if (DEBUG_MODE)
			cout << "model initiated" << endl;
	}
	void init(){
		//building 객체 생성 -> floor -> item, monsters 연쇄적으로 생성
		building = new Building{6};
		if (DEBUG_MODE) cout << "            creates building" << endl;
		condition = new Condition{ COUNTS };
		if (DEBUG_MODE) cout << "            creates condition" << endl;
		//character 생성 -> 0층의 시작 지점에 놓기
		//시작 지점을 어떻게 찾지??
		character = new Character{0, 0, CHARACTER,0};
		if (DEBUG_MODE) cout << "                creates character" << endl;
		screen = new Screen{};
		if (DEBUG_MODE) cout << "               created screen" << endl;
		mapFiller = new MapFiller{screen, 
			screen->map_row, screen->map_row + MAP_AREA_ROWS, 
			screen->map_col, screen->map_col + MAP_AREA_COLS, 
			character, building};
		if (DEBUG_MODE) cout << "             created mapFiller" << endl;
		mapInfoFiller = new MapInfoFiller{ screen,
			screen->info_row, screen->info_row + INFO_AREA_ROWS, 
			screen->info_col, screen->info_col + MAP_AREA_COLS, 
			character, condition };
		if (DEBUG_MODE) cout << "              created mapInfoFiller" << endl;
		messageFiller = new MessageFiller{ screen, 
			screen->message_row, screen->message_row + MESSAGE_AREA_ROWS, 
			screen->message_col, screen->message_col + MESSAGE_AREA_COLS, 
			"initial message" };
		if (DEBUG_MODE) cout << "              created messageFiller" << endl;
		conditionFiller = new ConditionFiller{ screen, 
			screen->condition_row, screen->condition_row + CONDITION_AREA_ROWS, 
			screen->condition_col, screen->condition_col + CONDITION_AREA_COLS, 
			condition };
		if (DEBUG_MODE) cout << "             created conditionFiller" << endl;
	}
	void update_position(int character_direction){ //현재 층의 캐릭터, 몬스터 위치 변경
		int x_delta[4] = { -1, 0, 1, 0 };
		int y_delta[4] = { 0, 1, 0, -1 };
		Floor *cur_floor = building->get_floor(character->floor_at);
		for (auto &monster : cur_floor->monsters) {
			//update monsters positions
			
			int direction = get_random() % 4;
			while (cur_floor->map[monster.x_pos + x_delta[direction]][monster.y_pos + y_delta[direction]] != INSIDE_WALL)
			{
				direction = get_random() % 4;
			}
			monster.move(direction);
		}
		//update characters position
	}
	void update_condition(){ //위 함수로 바뀐 상태에 따라 달라진 조건 update

	}
	int get_random(){
		srand((unsigned int)time(NULL));
		return rand();
	}
	char get_key(){ //유저로부터 키 받기

	}
	void run()
	{
		if (DEBUG_MODE)
			cout << "running" << endl;
		bool is_vic = false;
		do {
			//update_position();
			if (DEBUG_MODE) cout << "filling map" << endl;
			mapFiller->fill();
			if (DEBUG_MODE) cout << "filling map info" << endl;
			mapInfoFiller->fill();
			if (DEBUG_MODE) cout << "filling message" << endl;
			messageFiller->fill();
			if (DEBUG_MODE) cout << "filling condition" << endl;
			conditionFiller->fill();
			if (DEBUG_MODE) cout << "printing" << endl;
			screen->print();
			if (condition->is_victory()) {
				is_vic = true;
				break;
			}
			Sleep(1000);
		} while (!condition->is_fail());
		if (DEBUG_MODE)
		{
			cout << "run end : is_vic : " << is_vic << endl;
		}
	}
};