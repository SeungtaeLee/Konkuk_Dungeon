#pragma once

#include "Object.h"
#include "Condition.h"

using namespace std;

class Monster : public Object{
public:
	int monster_type;
	int attack_type;

	Monster(int x_pos, int y_pos, char symbol, int monster_type, int attack_type)
		:Object(x_pos, y_pos, symbol)
	{
		this->monster_type = monster_type;
		this->attack_type = attack_type;
	}
	/*
	bool attack(int type){
		//공격 타입에 따라 달라짐
		bool result = false;
		switch (type) {
		case 0:
			int x_delta[4] = {-1, 1, 0, 0 };
			int y_delta[4] = { 0 ,0, -1, 1 };
			for (int i = 0; i < 4; i++) {
				if(t)
			}
			break;
		}
	}*/
};