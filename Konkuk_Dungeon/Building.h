#pragma once

#include <vector>
#include "Floor.h"

using namespace std;

vector<string> map_paths{FLOOR_1, FLOOR_2, FLOOR_3, FLOOR_4, FLOOR_5, FLOOR_6};

class Building{
public:
	int floor_size;
	vector<Floor> floors;

	Building(int floor_size) {
		this->floor_size = floor_size;
		create_floors();
	}

	Floor* get_floor(int floor) {
		return &(floors[floor]);
	}

	void create_floors() {
		for (int i = 0; i < floor_size; i++) {
			//0ÃþºÎÅÍ »ý¼º
			Floor new_floor{map_paths[i], i, NUM_MOSNTERS};
			floors.push_back(new_floor);
		}
	}
};