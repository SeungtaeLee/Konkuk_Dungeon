#pragma once

#include "Object.h"
using namespace std;

class Item : public Object{
public:
	string message;
	int item_id;
	int floor_at;

	Item(int x_pos, int y_pos, char symbol, string message, int item_id)
		:Object(x_pos, y_pos, symbol)
	{
		this->message = message;
		this->item_id = item_id;
	}
};