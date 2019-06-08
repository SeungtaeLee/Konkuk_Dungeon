#pragma once

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include "Floor.h"
#include "Constants.h"

using namespace std;

//전역변수
vector<string> map_paths{MAP_1, MAP_2, MAP_3, MAP_4, MAP_5, MAP_6, MAP_7, MAP_8, MAP_9, MAP_10, MAP_11, MAP_12, MAP_13, MAP_14};

class Building{
public:
	int floor_size;
	vector<Floor> floors;

	Building(int floor_size) {
		this->floor_size = floor_size;
		create_floors();
		if (DEBUG_MODE) {
			cout << "all floors created(building)" << endl;
			//system("pause"); exit(0);
		}
	}

	Floor* get_floor(int floor) {
		return &(floors[floor]);
	}

	void create_floors() {
		if (DEBUG_MODE) cout << "creating floors" << endl;
		int random_idx;
		int ex_random_idxs[] = { -1, -1, -1, -1, -1, -1 };
		srand((unsigned int)time(NULL));
		vector<int> idx{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
		random_device rd;
		auto rng = std::default_random_engine{rd()};
		std::shuffle(begin(idx), end(idx), rng);
		if (DEBUG_MODE) {
			cout << "random map index for creating floors : ";
			for (int i : idx)
				cout << i << ", ";
			cout << endl;
		}
		for (int i = 0; i < floor_size; i++) {
			random_idx = idx[i];
			/*
			//(i + 1)층부터 생성
			int random_idx_trigger = 1;//while문 탈출조건
			while (random_idx_trigger == 1) {
				random_idx = rand() % 12;//랜덤변수 생성
				for(int j = 0; j < 6; j++) {//과거의 random_idx와 같은 값이 있는지 비교 과정
					if(ex_random_idxs[j] == random_idx) {//같은 경우 break후 다시 랜덤변수 생성
						break;
					}
					else {//다른 경우
						if(ex_random_idxs[j] == -1) {//-1이면 과거의 random_idx로 저장시키기
							ex_random_idxs[j] = random_idx;
							random_idx_trigger = 0;
							break;
						}
						else {//-1이 아니면 다음 ex_random_idxs와 비교하기
							continue;
						}
					}
				}
			}
			*/
			Floor new_floor{map_paths[random_idx], i, NUM_MOSNTERS};
			floors.push_back(new_floor);
			if (DEBUG_MODE) cout << "floor " << i << " created" << endl;
		}
	}
};