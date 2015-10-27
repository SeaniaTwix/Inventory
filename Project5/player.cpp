#include <wchar.h>
#include <string>
#include <iostream>
#include "deal.h"
#include "system.h"
#include "npc.h"

std::map<int, std::string> NPCList;
void addItemTo(Character* npc);

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

	NPC dummyNPC(-1);

	while (true) {
		getInputState(&dummyNPC);
		_getwch();
		initScreen();
	}

	return 0;
}

void getInputState(NPC* aDummyNPC) {

	std::map<int, std::string>::iterator it, begin, end;
	begin = NPCList.begin();
	end = NPCList.end();
	addItemTo(aDummyNPC);

	std::cout << "������ �ұ�? (b/s/q):" << std::endl;

	Deal deal;

	wchar_t c = _getwch();

	int input;
	std::cout << std::string(20, '-') << std::endl;
	/* Npc ��� ȣ�� */
	getNPCList(begin, end);
	std::cout << std::string(20, '-') << std::endl;
	std::cout << "������ �ŷ��Ͻðڽ��ϱ�?";
	std::cin >> input;
	std::cout << std::endl;

	NPC *cha = aDummyNPC;

	cha->setID(input);

	switch (c) {
	case 'q': // quit
		exit(__QUIT__);
		break;
	case 'b': // buy
		int ba;
		cha->printInventory();
		// ���� ��� ������ �����ϴ� �ڵ尡 ����
		std::cout << "���� ���? (�տ� �ִ� ��ȣ�� ����)" << std::endl;
		std::cin >> ba;
		deal.Buy(cha, ba);

		break;
	case 's': // sell
		int sa;
		cha->printInventory();
		// ���� ��� ������ �����ϴ� �ڵ尡 ����
		std::cout << "���� �ȱ�? (�տ� �ִ� ��ȣ�� ����)" << std::endl;
		std::cin >> sa;
		deal.Sell(cha, sa);

		break;
	default:
		std::cout << "ERR! �߸��� ����Դϴ�" << std::endl;
		break;
	}
}