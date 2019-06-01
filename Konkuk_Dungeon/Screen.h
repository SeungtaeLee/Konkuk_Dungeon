#pragma once

#include "Constants.h"
#include <vector>
#include <Windows.h>

class Screen{
public:
	char map[MAP_AREA_ROWS][MAP_AREA_COLS + 1];
	char info_area[INFO_AREA_ROWS][INFO_AREA_COLS + 1];
	char message_area[MESSAGE_AREA_ROWS][MESSAGE_AREA_COLS + 1];
	char condition_area[CONDITION_AREA_ROWS][CONDITION_AREA_COLS + 1];

	// 각 영역의 시작 위치들
	int map_row = 2;
	int map_col = 2;
	int message_row = 36;
	int message_col = 2;
	int info_row = 33;
	int info_col = 2;
	int condition_row = 2;
	int condition_col = 102;

	Screen()
	{
		HWND console = GetConsoleWindow();
		CONSOLE_CURSOR_INFO info;
		GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		info.bVisible = false;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		MoveWindow(console, 10, 10, 1500, 800, true);
		//문자 배열들 초기화
		memset(map, 0, sizeof(map));
		memset(info_area, 0, sizeof(info_area));
		memset(message_area, 0, sizeof(message_area));
		memset(condition_area, 0, sizeof(condition_area));
		//문자 배열들 각 열 끝에 널문자
		for (int i = 0; i < MAP_AREA_ROWS; i++)
			map[i][MAP_AREA_COLS] = '\0';
		for (int i = 0; i < INFO_AREA_ROWS; i++)
			map[i][INFO_AREA_COLS] = '\0';
		for (int i = 0; i < MESSAGE_AREA_ROWS; i++)
			map[i][MESSAGE_AREA_COLS] = '\0';
		for (int i = 0; i < CONDITION_AREA_ROWS; i++)
			map[i][CONDITION_AREA_COLS] = '\0';
	}
	void newScreen()
	{
		printf("Konkuk Dungeon\n");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┃                                                                                                    ┃                                        ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("┃                                                                                                                                             ┃\n");
		printf("┃                                                                                                                                             ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("┃                                                                                                                                             ┃\n");
		printf("┃                                                                                                                                             ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	}
	void gotoColRow(int col, int row)
	{
		COORD pos = { col, row };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	void print()
	{
		system("cls");
		newScreen();
		//map area 출력
		for (int i = 0; i < MAP_AREA_ROWS; i++)
		{
			gotoColRow(map_col, map_row + i);
			printf("%s", map[i]);
		}
		//info area 출력
		for (int i = 0; i < INFO_AREA_ROWS; i++)
		{
			gotoColRow(info_col, info_row + i);
			printf("%s", info_area[i]);
		}
		//message area 출력
		for (int i = 0; i < MESSAGE_AREA_ROWS; i++)
		{
			gotoColRow(message_col, message_row + i);
			printf("%s", message_area[i]);
		}
		//condition area 출력
		for (int i = 0; i < CONDITION_AREA_ROWS; i++)
		{
			gotoColRow(condition_col, condition_row + i);
			printf("%s", condition_area[i]);
		}
	}
};