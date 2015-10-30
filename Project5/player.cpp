#include <wchar.h>
#include <string>
#include <iostream>
#include "deal.h"
#include "system.h"
#include "npc.h"

std::map<int, std::string> NPCList;
void addItemTo(NPC* npc);

int main() {

	NPC dummyNPC(-1);

	addItemTo(&dummyNPC);

	while (true) {
		getInputState(&dummyNPC);
		_getwch();
		initScreen();
	}

	return 0;
}

void getInputState(NPC* aDummyNPC) {

	std::map<int, std::string>::iterator begin, end;

	Deal deal;

	char c;
	unsigned int howmany = 0;
	unsigned int a = 0;

	begin = NPCList.begin();
	end = NPCList.end();

	std::cout << std::string(20, '-') << std::endl;
	std::cout << "���� ������ �ִ� ��: " << me.wallet(CHECK) << std::endl;
	std::cout << "�κ��丮 ���" << std::endl;
	me.printInventory();
	std::cout << std::string(20, '-') << std::endl;
	std::cout << "Ȱ�� ���" << std::endl;
	std::cout << "b, Buy" << std::endl;
	std::cout << "s, Sell" << std::endl;
	std::cout << "q, Quit" << std::endl;
	std::cout << std::string(20, '-') << std::endl;


	std::cin >> c;

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
		me.printInventory();
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