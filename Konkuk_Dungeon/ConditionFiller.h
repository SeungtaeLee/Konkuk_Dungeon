#pragma once

#include "Filler.h"
#include "Condition.h"

class ConditionFiller : public Filler {
public:
	Condition* condition;

	ConditionFiller(Screen* screen, int x_start, int x_end, int y_start, int y_end, Condition *condition) 
		:Filler(screen, x_start, x_end, y_start, y_end)
	{
		this->condition = condition;
	}

	void fill(){


	}
};