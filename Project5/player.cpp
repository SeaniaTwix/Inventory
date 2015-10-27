#include <wchar.h>
#include <string>
#include <iostream>
#include "deal.h"
#include "system.h"
#include "npc.h"

NPC initGame();

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

	NPC* cha = &initGame();

	while (true) {
		getInputState(*cha);
		_getwch();
		initScreen();
	}

	return 0;
}

void getInputState(NPC cha) {

	std::map<int, std::string>::iterator it, begin, end;

	std::cout << "무엇을 할까? (b/s/q):" << std::endl;

	Deal deal;

	wchar_t c = _getwch();

	int input;
	std::cout << std::string(20, '-') << std::endl;
	/* Npc 목록 호출 */
	getNPCList(begin, end);
	std::cout << std::string(20, '-') << std::endl;
	std::cout << "누구와 거래하시겠습니까?";
	std::cin >> input;
	std::cout << std::endl;

	cha.setID(input);
	int charaNums = cha.retID();

	//c = '\0';

	switch (c) {
	case 'q': // quit
		exit(__QUIT__);
		break;
	case 'b': // buy
		int ba;
		cha.printInventory();
		// 아직 목록 순서에 대응하는 코드가 없음
		std::cout << "무얼 살까? (앞에 있는 번호를 쓰자)" << std::endl;
		std::cin >> ba;
		deal.Buy(&cha, ba);

		break;
	case 's': // sell
		int sa;
		cha.printInventory();
		// 아직 목록 순서에 대응하는 코드가 없음
		std::cout << "무얼 팔까? (앞에 있는 번호를 쓰자)" << std::endl;
		std::cin >> sa;
		deal.Sell(&cha, sa);

		break;
	default:
		std::cout << "ERR! 잘못된 명령입니다" << std::endl;
		break;
	}
}