#pragma once

#include <vector>
#include "Object.h"
#include "Item.h"
using namespace std;

class Character : public Object{
public:
	int floor_at;
	vector<Item> inventory;

	Character(int x_pos, int y_pos, char symbol, int floor_at)
		:Object(x_pos, y_pos, symbol)
	{
		this->floor_at = floor_at;
	}

	void get_item(Item new_item){
		//�ڽ��� �ڸ��� �ִ� ������ �ݱ�
		inventory.push_back(new_item);
	}
};