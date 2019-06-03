#pragma once

#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <random>
#include "Character.h"
#include "Building.h"
#include "Condition.h"
#include "Screen.h"
#include "MapFiller.h"
#include "MapInfoFiller.h"
#include "MessageFiller.h"
#include "ConditionFiller.h"
vector<char> item_symbols2{ LAPTOP, BOOK, STUDENT_CARD, ICE_COFFEE, REPORT, CERTIFICATE };

class Controller {
public:
	random_device rd;
	Floor *cur_floor;
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
		Floor *floor = building->get_floor(0);
		int init_x, init_y;
		for (int i = 0; i < MAP_AREA_ROWS; i++) {
			for (int j = 0; j < MAP_AREA_COLS; j++) {
				if (floor->map[i][j] == DOWN_PORTAL)
				{
					init_x = i; init_y = j;
				}
			}
		}
		character = new Character{init_x, init_y, CHARACTER,0};
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
		cur_floor = building->get_floor(character->floor_at);
		for (auto &monster : cur_floor->monsters) {
			//update monsters positions
			
			int direction = rd() % 4;
			while (cur_floor->map[monster.x_pos + x_delta[direction]][monster.y_pos + y_delta[direction]] != INSIDE_WALL)
			{
				direction = rd() % 4;
			}
			monster.move(direction);
		}
		//update characters position 
		switch (cur_floor->map[character->x_pos + x_delta[character_direction]][character->y_pos + y_delta[character_direction]])
		{
		case INSIDE_WALL:
		case UP_PORTAL:
		case DOWN_PORTAL:
			character->move(character_direction);
			break;
		}
	}
	void update_condition(){ //위 함수로 바뀐 상태에 따라 달라진 조건 update
		if (DEBUG_MODE) cout << "in update condition" << endl;
		cur_floor = building->get_floor(character->floor_at);
		//현 위치가 포탈인경우 층 이동
		if (character->floor_at < 6 && cur_floor->map[character->x_pos][character->y_pos] == UP_PORTAL)
		{
			if (DEBUG_MODE) cout << "going up" << endl;
			character->floor_at++;
			cur_floor = building->get_floor(character->floor_at);
			for (int i = 0; i < MAP_AREA_ROWS; i++) {
				for (int j = 0; j < MAP_AREA_COLS; j++) {
					if (cur_floor->map[i][j] == DOWN_PORTAL)
					{
						character->x_pos = i;
						character->y_pos = j;
					}
				}
			}
			return;
		}
		if (character->floor_at > 0 && cur_floor->map[character->x_pos][character->y_pos] == DOWN_PORTAL)
		{
			if (DEBUG_MODE) cout << "going down" << endl;
			character->floor_at--;
			cur_floor = building->get_floor(character->floor_at);
			for (int i = 0; i < MAP_AREA_ROWS; i++) {
				for (int j = 0; j < MAP_AREA_COLS; j++) {
					if (cur_floor->map[i][j] ==UP_PORTAL)
					{
						character->x_pos = i;
						character->y_pos = j;
					}
				}
			}
			return;
		}
		//아이템 확인
		for (const Item &item : character->inventory)
		{
			condition->victory_conditions[item.item_id] = true;
		}
		if (DEBUG_MODE) cout << "item check" << endl;
		//캐릭터 현재층 확인 & 최종 위치 도달 확인
		if (DEBUG_MODE) cout << "if reached" << endl;
		if (character->floor_at == 6 && cur_floor->map[character->x_pos][character->y_pos] == UP_PORTAL)
		{
			condition->victory_conditions[6] = true;
		}
		else {
			condition->victory_conditions[6] = false;
		}
		//카운트 감소
		condition->count--;
		if (condition->count <= 0)
			condition->fail_condition = true;
		for (const auto &monster : cur_floor->monsters) {
			if (monster.x_pos == character->x_pos && monster.y_pos == character->y_pos)
				condition->fail_condition = true;
		}
	}
	char get_key(){ //유저로부터 키 받기
		char key = _getch();
		return key;
	}
	void run()
	{
		cur_floor = building->get_floor(character->floor_at);
		if (DEBUG_MODE)
			cout << "running" << endl;
		do {
			char new_key = get_key();
			if (DEBUG_MODE)
				cout << "user key : " << new_key << endl;
			switch (new_key)
			{
			case 'w':
				update_position(0);
				break;
			case 'a':
				update_position(3);
				break;
			case 's':
				update_position(2);
				break;
			case 'd':
				//이동하는 경우
				//update 안하는 경우 다시 get_key();
				update_position(1);
				break;
			case 'i':
				//아이템 줍기
				if (cur_floor->items.front().x_pos != character->x_pos || cur_floor->items.front().y_pos != character->y_pos)
				{
					cout << "NO ITEM " << cur_floor->items.size() << endl;
					printf("char x : %d, y : %d || item : x : %d, y : %d\n", character->x_pos, character->y_pos, cur_floor->items.front().x_pos, cur_floor->items.front().y_pos);
					break;
				}
				else {
					if (DEBUG_MODE) cout << "get item" << endl;
					std::copy(cur_floor->items.begin(), cur_floor->items.end(), back_inserter(character->inventory));
					cur_floor->items.pop_back();
					if(DEBUG_MODE) cout << character->inventory.size() << endl;
					break;
				}
			}
			update_condition();
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
				break;
			}
			Sleep(50);
		} while (!condition->is_fail());
	}
};