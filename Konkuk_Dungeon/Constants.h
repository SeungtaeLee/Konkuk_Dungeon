#pragma once

// 스크린 상수들
constexpr auto SCREEN_ROWS = 38;
constexpr auto SCREEN_COLS = 143;
constexpr auto MAP_AREA_ROWS = 30;
constexpr auto MAP_AREA_COLS = 100;
constexpr auto INFO_AREA_ROWS = 2;
constexpr auto INFO_AREA_COLS = 142;
constexpr auto MESSAGE_AREA_ROWS = 2;
constexpr auto MESSAGE_AREA_COLS = 142;
constexpr auto CONDITION_AREA_ROWS = 30;
constexpr auto CONDITION_AREA_COLS = 40;

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

//아이템 메시지들
constexpr auto ITEM1_MESSAGE = "item 1 message";
constexpr auto ITEM2_MESSAGE = "item 2 message";
constexpr auto ITEM3_MESSAGE = "item 3 message";
constexpr auto ITEM4_MESSAGE = "item 4 message";
constexpr auto ITEM5_MESSAGE = "item 5 message";
constexpr auto ITEM6_MESSAGE = "item 6 message";

//각층 맵 텍스트파일 주소
constexpr auto MAP_1 = "./map/map_1.txt";
constexpr auto MAP_2 = "./map/map_2.txt";
constexpr auto MAP_3 = "./map/map_3.txt";
constexpr auto MAP_4 = "./map/map_4.txt";
constexpr auto MAP_5 = "./map/map_5.txt";
constexpr auto MAP_6 = "./map/map_6.txt";
constexpr auto MAP_7 = "./map/map_7.txt";
constexpr auto MAP_8 = "./map/map_8.txt";
constexpr auto MAP_9 = "./map/map_9.txt";
constexpr auto MAP_10 = "./map/map_10.txt";
constexpr auto MAP_11 = "./map/map_11.txt";
constexpr auto MAP_12 = "./map/map_12.txt";

constexpr auto NUM_MOSNTERS = 5;

constexpr auto COUNTS = 500;

constexpr bool DEBUG_MODE = false;