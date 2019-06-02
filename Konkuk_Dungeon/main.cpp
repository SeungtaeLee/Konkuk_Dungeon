#include <iostream>
#include "Controller.h"

using namespace std;

int main()
{
	Controller *controller = new Controller{};
	controller->run();
	return 0;
}