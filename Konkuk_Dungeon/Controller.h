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
		//building 객체 생성 -> floor -> item, monsters 연쇄적으로 생성
		//character 생성 -> 0층의 시작 지점에 놓기
	}
	void update_position(){ //현재 층의 캐릭터, 몬스터 위치 변경

	}
	void update_condition(){ //위 함수로 바뀐 상태에 따라 달라진 조건 update

	}
	double get_random(){ //0~1
		srand((unsigned int)time(NULL));
		return (double)rand() / RAND_MAX;
	}
	char get_key(){ //유저로부터 키 받기

	}
};