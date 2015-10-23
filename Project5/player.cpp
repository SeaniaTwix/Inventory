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

	std::cout << "������ �ұ�? (b/s/q):" << std::endl;

	Deal deal;

	wchar_t c = _getwch();


	int input;
	/* Npc ��� ȣ�� */
	showNpcNameList();
	std::cout << std::string("-", 20);
	std::cout << "������ �ŷ��Ͻðڽ��ϱ�?";
	std::cin >> input;
	std::cout << std::endl;

	Character cha;
	cha.setID(input);
	int charaNums = cha.retID();

	switch (c) {
	case 'q': // quit
		exit(__QUIT__);
		break;
	case 'b': // buy

		cha.printInventory();
		std::cout << "���� ���? (�տ� �ִ� ��ȣ�� ����)" << std::endl;
		int c = _getwch();
		deal.Buy(&cha, c);

		break;
	case 's': // sell
		
		me.printInventory();
		std::cout << "���� �ȱ�? (�տ� �ִ� ��ȣ�� ����)" << std::endl;
		int c = _getwch();
		deal.Sell(&cha, c);

		break;
	default:
		std::cout << "ERR! �߸��� ����Դϴ�" << std::endl;
		break;
	}
}