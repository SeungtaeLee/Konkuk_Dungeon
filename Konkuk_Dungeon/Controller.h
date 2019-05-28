#pragma once

#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "Building.h"
#include "Condition.h"
#include "MapFiller.h"
#include "MapInfoFiller.h"
#include "MessageFiller.h"
#include "ConditionFiller.h"

class Controller {
public:
	Character *character;
	Building *building;
	Condition *condition;
	MapFiller *mapFiller;
	MapInfoFiller *mapInfoFiller;
	MessageFiller *messageFiller;
	ConditionFiller *conditionFiller;

	Controller(
		Character *character,
		Building *building,
		Condition *condition,
		MapFiller *mapFiller,
		MapInfoFiller *mapInfoFiller,
		MessageFiller *messageFiller,
		ConditionFiller *conditionFiller
	) {
		this->character = character;
		this->building = building;
		this->condition = condition;
		this->mapFiller = mapFiller;
		this->mapInfoFiller = mapInfoFiller;
		this->messageFiller = messageFiller;
		this->conditionFiller = conditionFiller;
	}
	void init(){
		//building ��ü ���� -> floor -> item, monsters ���������� ����
		//character ���� -> 0���� ���� ������ ����
	}
	void update_position(){ //���� ���� ĳ����, ���� ��ġ ����

	}
	void update_condition(){ //�� �Լ��� �ٲ� ���¿� ���� �޶��� ���� update

	}
	double get_random(){ //0~1
		srand((unsigned int)time(NULL));
		return (double)rand() / RAND_MAX;
	}
	char get_key(){ //�����κ��� Ű �ޱ�

	}
};