#pragma once

class Object {
public:
	int x_pos, y_pos;
	char symbol;

	Object(int x_pos, int y_pos, char symbol) {
		this->x_pos = x_pos;
		this->y_pos = y_pos;
		this->symbol = symbol;
	}
	virtual void move(int direction) //벽인 경우는 컨트롤러 업데이트 x
	{
		int x_delta[4] = { -1, 0, 1, 0 };
		int y_delta[4] = { 0, 1, 0, -1 };
		this->x_pos += x_delta[direction];
		this->y_pos += y_delta[direction];
	}
};