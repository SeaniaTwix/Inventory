#include <wchar.h>
#include <string>
#include <iostream>
#include "deal.h"
#include "system.h"
#include "npc.h"

void initGame();
Character cha;

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

	initGame();

	while (true) {
		getInputState();
		_getwch();
		initScreen();
	}

	return 0;
}

void getInputState() {

	std::map<int, std::string>::iterator it, begin, end;

	std::cout << "무엇을 할까? (b/s/q):" << std::endl;

	Deal deal;

	wchar_t c = _getwch();

	int input;
	/* Npc 목록 호출 */
	getNPCList(begin, end);
	std::cout << std::string("-", 20);
	std::cout << "누구와 거래하시겠습니까?";
	std::cin >> input;
	std::cout << std::endl;

	Character doWithThis = cha;

	doWithThis.setID(input);
	int charaNums = doWithThis.retID();

	c = '\0';

	switch (c) {
	case 'q': // quit
		exit(__QUIT__);
		break;
	case 'b': // buy
		int ba;
		doWithThis.printInventory();
		// 아직 목록 순서에 대응하는 코드가 없음
		std::cout << "무얼 살까? (앞에 있는 번호를 쓰자)" << std::endl;
		std::cin >> ba;
		deal.Buy(&doWithThis, ba);

		break;
	case 's': // sell
		int sa;
		doWithThis.printInventory();
		// 아직 목록 순서에 대응하는 코드가 없음
		std::cout << "무얼 팔까? (앞에 있는 번호를 쓰자)" << std::endl;
		std::cin >> sa;
		deal.Sell(&doWithThis, sa);

		break;
	default:
		std::cout << "ERR! 잘못된 명령입니다" << std::endl;
		break;
	}
}