#pragma once

#include <vector>
using namespace std;

class Condition {
public:
	vector<bool> victory_conditions{false, false, false, false, false, false, false};
	bool fail_condition{ false };
	int count;
	vector<int> item_required;
	int num_vic_conds;

	Condition(int count) {
		this->count = count;
	}

	bool is_victory() {
		bool result = true;
		for (const bool &cond : victory_conditions) {
			result = result && cond;
		}
		return result;
	}

	bool is_fail() {
		return fail_condition;
	}
};