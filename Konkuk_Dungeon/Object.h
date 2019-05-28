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

	virtual void move(int direction) //���� ���� ��Ʈ�ѷ� �������� ������Ʈ x
	{
		switch (direction)
		{
		case 0:
			//up
			this->y_pos++;
			break;
		case 1:
			//down
			this->y_pos--;
			break;
		case 2:
			//right
			this->x_pos++;
			break;
		case 3:
			//left
			this->x_pos--;
			break;
		}
	}
};