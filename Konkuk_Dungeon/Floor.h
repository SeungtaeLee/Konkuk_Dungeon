#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Item.h"
#include "Monster.h"
using namespace std;

vector<char> item_symbols{ LAPTOP, BOOK, STUDENT_CARD, ICE_COFFEE, REPORT, CERTIFICATE };
vector<string> messages{ITEM1_MESSAGE, ITEM2_MESSAGE, ITEM3_MESSAGE, ITEM4_MESSAGE, ITEM5_MESSAGE, ITEM6_MESSAGE};

class Floor {
public:
	string map_path;
	int item_index;
	int num_monsters;
	vector<Item> items;
	vector<Monster> monsters;
	char map[MAP_AREA_ROWS][MAP_AREA_COLS];

	Floor(string map_path, int item_index, int num_monsters) {
		this->map_path = map_path;
		this->item_index = item_index;
		this->num_monsters = num_monsters;
		map_init(this->map_path);
		create_items(this->item_index);
		create_monsters(this->num_monsters);
	}

	void map_init(string map_path) {
		//객체 생성시 호출, map_path에 있는 지형 값을 읽어와 map에 할당한다. ifstream이용
		ifstream ifs;
		ifs.open(map_path);
		if (!ifs) {
			cout << "다음 파일이 없습니다. (" << map_path << ")" << endl;
			exit(0);
		}
	}
	void create_items(int idx) {
		//층에 존재할  Item 생성(인덱스 : idx)
		pair<int, int> new_position = get_position(this->map);
		Item new_item{ new_position.first, new_position.second, item_symbols[idx], messages[idx], idx};
		items.push_back(new_item);
	}
	void create_monsters(int num) {
		//층에 존재할 Monster들 생성(갯수 : num)
		for (int i = 0; i < num; i++) {
			pair<int, int> new_position = get_position(this->map);
			//Monster new_monster{}; => 생성해야함.
			monsters.push_back(new_monster);
		}
	}
	pair<int, int> get_position(char (*map)[MAP_AREA_COLS]) {
		srand((unsigned)time(NULL));
		int x_pos, y_pos;
		x_pos = rand() % MAP_AREA_ROWS;
		y_pos = rand() % MAP_AREA_COLS;
		while (map[x_pos][y_pos] != INSIDE_WALL) {
			x_pos = rand() % MAP_AREA_ROWS;
			y_pos = rand() % MAP_AREA_COLS;
		}
		return pair<int, int>(x_pos, y_pos);
	}
};