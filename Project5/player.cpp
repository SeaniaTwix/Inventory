#include <wchar.h>
#include <iostream>
#include "deal.h"
#include "system.h"
#include "player.h"

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

	c = '\0';

	switch (c) {
	case 'q': // quit
		exit(__QUIT__);
		break;
	case 'b': // buy
		int ba;
		cha.printInventory();
		// ���� ��� ������ �����ϴ� �ڵ尡 ����
		std::cout << "���� ���? (�տ� �ִ� ��ȣ�� ����)" << std::endl;
		std::cin >> ba;
		deal.Buy(&cha, ba);

		break;
	case 's': // sell
		int sa;
		me.printInventory();
		// ���� ��� ������ �����ϴ� �ڵ尡 ����
		std::cout << "���� �ȱ�? (�տ� �ִ� ��ȣ�� ����)" << std::endl;
		std::cin >> sa;
		deal.Sell(&cha, sa);

		break;
	default:
		std::cout << "ERR! �߸��� ����Դϴ�" << std::endl;
		break;
	}
}