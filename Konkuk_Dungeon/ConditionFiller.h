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
	void fill(){
		if (DEBUG_MODE) cout << "\tfiller() in conditionfiller" << endl;
		for (int i = 0; i < 7; i++) {
			sprintf_s(screen->condition_area[i], "Condition %d : %s", i + 1, condition->victory_conditions[i] ? "true" : "false");
		}
		if (DEBUG_MODE) {
			cout << "filled all condition" << endl;
		}
		
	}
};