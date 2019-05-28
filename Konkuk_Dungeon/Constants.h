#pragma once

// 스크린 상수들
constexpr auto SCREEN_ROWS = 100;
constexpr auto SCREEN_COLS = 100;
constexpr auto MAP_ROWS = 50;
constexpr auto MAP_COLS = 50;

// 지도상 심볼들
constexpr auto CHARACTER = '@';
constexpr auto MONSTER = '+';

// 1층 아이템
constexpr auto LAPTOP = 'L';
// 2층 아이템
constexpr auto BOOK = 'B';
// 3층 아이템
constexpr auto STUDENT_CARD = 'S';
// 4층 아이템
constexpr auto ICE_COFFEE = 'I';
// 5층 아이템
constexpr auto REPORT = 'R';
// 6층 아이템
constexpr auto CERTIFICATE = 'C';

constexpr auto WALL = '#';
constexpr auto UP_PORTAL = '^';
constexpr auto DOWN_PORTAL = '_';
constexpr auto INSIDE_WALL = ' ';
constexpr auto OUTSIDE_WALL = '.';
constexpr auto ITEMS = { LAPTOP, BOOK, STUDENT_CARD, ICE_COFFEE, REPORT, CERTIFICATE };

//아이템 메시지들
constexpr auto ITEM1_MESSAGE = "item 1 message";
constexpr auto ITEM2_MESSAGE = "item 2 message";
constexpr auto ITEM3_MESSAGE = "item 3 message";
constexpr auto ITEM4_MESSAGE = "item 4 message";
constexpr auto ITEM5_MESSAGE = "item 5 message";
constexpr auto ITEM6_MESSAGE = "item 6 message";
constexpr auto ITEM_MESSAGES = {
	ITEM1_MESSAGE, ITEM2_MESSAGE, ITEM3_MESSAGE, ITEM4_MESSAGE, ITEM5_MESSAGE, ITEM6_MESSAGE
};

//각층 맵 텍스트파일 주소
constexpr auto FLOOR_1 = "./map/map_floor1.txt";
constexpr auto FLOOR_2 = "./map/map_floor2.txt";
constexpr auto FLOOR_3 = "./map/map_floor3.txt";
constexpr auto FLOOR_4 = "./map/map_floor4.txt";
constexpr auto FLOOR_5 = "./map/map_floor5.txt";
constexpr auto FLOOR_6 = "./map/map_floor6.txt";

constexpr auto NUM_MOSNTERS = 5;