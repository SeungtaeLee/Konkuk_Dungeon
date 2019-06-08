#pragma once

#include "Filler.h"
#include "Condition.h"

#include <iostream>

class ConditionFiller : public Filler {
public:
	Condition* condition;
	
	ConditionFiller(Screen* screen, int x_start, int x_end, int y_start, int y_end, Condition *condition) 
		:Filler(screen, x_start, x_end, y_start, y_end)
	{
		this->condition = condition;
	}
	vector<string> item_condition{"��Ʈ��(L)    ", "����å(B)    ", "�л���(S)    ", "���̽�Ŀ��(I)", "����Ʈ(R)    ", "������(C)    "};
	void fill(){
		if (DEBUG_MODE) cout << "\tfiller() in conditionfiller" << endl;
		for (int i = 0; i < 6; i++) {
			sprintf_s(screen->condition_area[i], "%s : %s\n", item_condition[i].c_str(), condition->victory_conditions[i] ? "ã�Ҵ�" : "ã�ƾ� �Ѵ�");
		}
		if (DEBUG_MODE) {
			cout << "filled all condition" << endl;
		}
		
	}
};