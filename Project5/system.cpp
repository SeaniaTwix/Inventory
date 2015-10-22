#include "system.h"
#include <iostream>
#include <string>

void initScreen() {

	// Clear hijacker
	/*
	while (char ch = _getch()) {
	} //*/

	std::cout << std::string(1000, '\n');
	COORD cur = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}