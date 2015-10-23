#include <wchar.h>
#include <iostream>
#include "items.h"
#include "deal.h"
#include "system.h"
#include "npc.h"

#define __QUIT__ 0

void getInputState();
void showNpcNameList();

int main() {

	Character me;

	/*
	Inventory inven;

	{ using namespace ITEM;
		inven.inputItem(APPLE);
	}

	inven.viewInv();
	std::cout << "you have " << money << " money now" << std::endl;

	_getwch();
	//*/

	while (true) {
		getInputState();
		_getwch();
		initScreen();
	}

	return 0;
}

void getInputState() {

	std::cout << "무엇을 할까? (b/s/q):" << std::endl;

	Deal deal;

	wchar_t c = _getwch();


	int input;
	/* Npc 목록 호출 */
	showNpcNameList();
	std::cout << std::string("-", 20);
	std::cout << "누구와 거래하시겠습니까?";
	std::cin >> input;
	std::cout << std::endl;


	switch (c) {
	case 'q': // quit
		exit(__QUIT__);
		break;
	case 'b': // buy
		break;
	case 's': // sell
		//do something
		break;
	default:
		std::cout << "ERR! 잘못된 명령입니다" << std::endl;
		break;
	}
}