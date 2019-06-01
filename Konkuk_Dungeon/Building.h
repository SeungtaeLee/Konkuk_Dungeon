#pragma once

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Floor.h"

using namespace std;

//��������
vector<string> map_paths{MAP_1, MAP_2, MAP_3, MAP_4, MAP_5, MAP_6, MAP_7, MAP_8, MAP_9, MAP_10, MAP_11, MAP_12};

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
		int random_idx;
		int ex_random_idxs[] = { -1, -1, -1, -1, -1, -1 };
		srand((unsigned int)time(NULL));
		for (int i = 0; i < floor_size; i++) {
			//(i + 1)������ ����
			//random_idx = get_random(int from, int to);
			int random_idx_trigger = 1;//while�� Ż������
			while (random_idx_trigger == 1) {
				random_idx = rand() % 12 + 1;//�������� ����
				for(int j = 0; j < 6; j++) {//������ random_idx�� ���� ���� �ִ��� �� ����
					if(ex_random_idxs[j] == random_idx) {//���� ��� break�� �ٽ� �������� ����
						break;
					}
					else {//�ٸ� ���
						if(ex_random_idxs[j] == -1) {//-1�̸� ������ random_idx�� �����Ű��
							ex_random_idxs[j] = random_idx;
							random_idx_trigger = 0;
							break;
						}
						else {//-1�� �ƴϸ� ���� ex_random_idxs�� ���ϱ�
							continue;
						}
					}
				}
			}
			Floor new_floor{map_paths[random_idx], i, NUM_MOSNTERS};
			floors.push_back(new_floor);
		}
	}
};