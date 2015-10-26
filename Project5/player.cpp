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

	std::cout << "������ �ұ�? (b/s/q):" << std::endl;

	Deal deal;

	wchar_t c = _getwch();

	int input;
	/* Npc ��� ȣ�� */
	getNPCList(begin, end);
	std::cout << std::string("-", 20);
	std::cout << "������ �ŷ��Ͻðڽ��ϱ�?";
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
		// ���� ��� ������ �����ϴ� �ڵ尡 ����
		std::cout << "���� ���? (�տ� �ִ� ��ȣ�� ����)" << std::endl;
		std::cin >> ba;
		deal.Buy(&doWithThis, ba);

		break;
	case 's': // sell
		int sa;
		doWithThis.printInventory();
		// ���� ��� ������ �����ϴ� �ڵ尡 ����
		std::cout << "���� �ȱ�? (�տ� �ִ� ��ȣ�� ����)" << std::endl;
		std::cin >> sa;
		deal.Sell(&doWithThis, sa);

		break;
	default:
		std::cout << "ERR! �߸��� ����Դϴ�" << std::endl;
		break;
	}
}