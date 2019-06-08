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
#include "Constants.h"
#include <Windows.h>
#include <random>
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
	char map[MAP_AREA_ROWS][MAP_AREA_COLS + 1];

	Floor(string map_path, int item_index, int num_monsters) {
		this->map_path = map_path;
		this->item_index = item_index;
		this->num_monsters = num_monsters;
		if (DEBUG_MODE)  cout << "Floor initiating(" << item_index << ")" << endl;
		map_init(this->map_path);
		create_items(this->item_index);
		create_monsters(this->num_monsters + this->item_index);
	}

	void map_init(string map_path) {
		//��ü ������ ȣ��, map_path�� �ִ� ���� ���� �о�� map�� �Ҵ��Ѵ�. ifstream�̿�
		if (DEBUG_MODE) cout << "map init(floor : " << item_index << ",map_path : " << map_path << ")" << endl;
		ifstream ifs;
		ifs.open(map_path);
		if (!ifs) {
			cout << "���� ������ �����ϴ�. (" << map_path << ")" << endl;
			system("pause");
			exit(0);
		}
		int idx = 0;
		string temp;
		while (getline(ifs, temp)) {
			strcpy_s(map[idx], temp.c_str());
			idx++;
		}
		ifs.close();
		if (DEBUG_MODE) cout << "map initiated(total lines : " << idx << ")" << endl;
	}
	void create_items(int idx) {
		//���� ������  Item ����(�ε��� : idx)
		if (DEBUG_MODE) cout << "creating item(floor : " << item_index << ")"<< endl;
		pair<int, int> new_position = get_position(map);
		
		this->items.emplace_back(new_position.first, new_position.second, item_symbols[idx], messages[idx], idx);
		if (DEBUG_MODE) cout << "got position for item" << items.front().item_id << endl;
	}
	void create_monsters(int num) {
		//���� ������ Monster�� ����(���� : num)
		if (DEBUG_MODE) cout << "creating monsters(num: " << num << ")" << endl;
		for (int i = 0; i < num; i++) {
			pair<int, int> new_position = get_position(map);
			monsters.emplace_back(new_position.first, new_position.second, MONSTER, -1, -1);
			if (DEBUG_MODE) cout << "monster[" << i << "] created" << endl;
		}
	}
	pair<int, int> get_position(char (*map)[MAP_AREA_COLS + 1]) {
		random_device rd;
		int x_pos, y_pos;
		x_pos = rd() % MAP_AREA_ROWS;
		y_pos = rd() % MAP_AREA_COLS;
		while (map[x_pos][y_pos] != INSIDE_WALL) {
			x_pos = rd() % MAP_AREA_ROWS;
			y_pos = rd() % MAP_AREA_COLS;
			//if (DEBUG_MODE) printf("got symbol at (%d, %d) : %d\n", x_pos, y_pos, (int)map[x_pos][y_pos]);
			//if(DEBUG_MODE) Sleep(1000);
		}
		if (DEBUG_MODE) cout << "got valid position" << endl;
		return pair<int, int>(x_pos, y_pos);
	}
};