#include <wchar.h>
#include <string>
#include <iostream>
#include "deal.h"
#include "system.h"
#include "npc.h"

std::map<int, std::string> NPCList;
void addItemTo(NPC* npc);

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
	unsigned int howmany = 0;
	unsigned int a = 0;

	/*if (c != 'b' || c != 's' || c != 'q') {
		std::cout << "ERR! �߸��� ����Դϴ�" << std::endl;

		return;
	}*/

	int input;
	std::cout << std::string(20, '-') << std::endl;
	/* Npc ��� ȣ�� */
	getNPCList(begin, end);
	std::cout << std::string(20, '-') << std::endl;
	std::cout << "������ �ŷ��Ͻðڽ��ϱ�? (��ȣ) : ";
	std::cin >> input;
	std::cout << std::endl;

	NPC *cha = aDummyNPC;

	cha->setID(input);

	switch (c) {
	case 'q': // quit
		exit(__QUIT__);
		break;
	case 'b': // buy
		cha->printInventory();
		// ���� ��� ������ �����ϴ� �ڵ尡 ����
		std::cout << "���� ���? (�տ� �ִ� ��ȣ�� ����)" << std::endl;
		std::cin >> a;
		std::cout << "����:";
		std::cin >> howmany;
		std::cout << std::endl;
		deal.Buy(cha, a, howmany);

		break;
	case 's': // sell
		cha->printInventory();
		// ���� ��� ������ �����ϴ� �ڵ尡 ����
		std::cout << "���� �ȱ�? (�տ� �ִ� ��ȣ�� ����)" << std::endl;
		std::cin >> a;
		std::cout << "����:";
		std::cin >> howmany;
		std::cout << std::endl;
		deal.Sell(cha, a, howmany);

		break;
	default:
		std::cout << "ERR! �߸��� ����Դϴ�" << std::endl;
		break;
	}
}