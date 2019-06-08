#pragma once

// ��ũ�� �����
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

// ������ �ɺ���
constexpr auto CHARACTER = '@';
constexpr auto MONSTER = '+';

// 1�� ������
constexpr auto LAPTOP = 'L';
// 2�� ������
constexpr auto BOOK = 'B';
// 3�� ������
constexpr auto STUDENT_CARD = 'S';
// 4�� ������
constexpr auto ICE_COFFEE = 'I';
// 5�� ������
constexpr auto REPORT = 'R';
// 6�� ������
constexpr auto CERTIFICATE = 'C';

constexpr auto WALL = '#';
constexpr auto UP_PORTAL = '^';
constexpr auto DOWN_PORTAL = '_';
constexpr auto INSIDE_WALL = ' ';
constexpr auto OUTSIDE_WALL = '.';

//������ �޽�����
constexpr auto ITEM1_MESSAGE = "[�� Ʈ ��]\n��  ��Ʈ�ϰ� Ű��Ų�� �ִٸ� ���� �� �� �־��"; // L ��Ʈ��
constexpr auto ITEM2_MESSAGE = "[�� �� å]\n��  ���ݺ��� ���λ��̾�"; // B å
constexpr auto ITEM3_MESSAGE = "[�� �� ��]\n��  �̰� ���� �Ҿ���ȴ� �л������ݾ�....?!!!!!"; // S �л���
constexpr auto ITEM4_MESSAGE = "[�� �� �� Ŀ ��]\n��  ī������ ���� ��� ������ ��..."; // I ���̽�Ŀ��
constexpr auto ITEM5_MESSAGE = "[�� �� Ʈ]\n��  ���ñ��� ������ ����� ���̾�...!!!!"; // R ����Ʈ
constexpr auto ITEM6_MESSAGE = "[�� �� ��]\n��  ������ �а� Ȯ���̴�....!!!"; // C ������

//���� �� �ؽ�Ʈ���� �ּ�
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
constexpr auto MAP_13 = "./map/map_13.txt";
constexpr auto MAP_14 = "./map/map_14.txt";

//��Ʈ�� �� ���� ���� ȭ��
constexpr auto INTRO = "intro.txt";
constexpr auto CLEAR = "clear.txt";
constexpr auto FAIL = "failure.txt";

constexpr auto NUM_MOSNTERS = 5;

constexpr auto COUNTS = 100000;

constexpr bool DEBUG_MODE = false;