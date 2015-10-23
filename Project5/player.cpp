#include <wchar.h>
#include <iostream>
#include "items.h"
#include "deal.h"
#include "system.h"
#include "npc.h"
#include "player.h"

#define __QUIT__ 0

void getInputState();
void showNpcNameList();

int main() {

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

	Character cha;
	cha.setID(input);
	int charaNums = cha.retID();

	c = '\0';

	switch (c) {
	case 'q': // quit
		exit(__QUIT__);
		break;
	case 'b': // buy
		int ba;
		cha.printInventory();
		std::cout << "무얼 살까? (앞에 있는 번호를 쓰자)" << std::endl;
		std::cin >> ba;
		deal.Buy(&cha, ba);

		break;
	case 's': // sell
		int sa;
		me.printInventory();
		std::cout << "무얼 팔까? (앞에 있는 번호를 쓰자)" << std::endl;
		std::cin >> sa;
		deal.Sell(&cha, sa);

		break;
	default:
		std::cout << "ERR! 잘못된 명령입니다" << std::endl;
		break;
	}
}