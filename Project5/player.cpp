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
	std::cout << "내가 가지고 있는 돈: " << me.wallet(CHECK) << std::endl;
	std::cout << "인벤토리 목록" << std::endl;
	me.printInventory();
	std::cout << std::string(20, '-') << std::endl;
	std::cout << "활동 목록" << std::endl;
	std::cout << "b, Buy" << std::endl;
	std::cout << "s, Sell" << std::endl;
	std::cout << "q, Quit" << std::endl;
	std::cout << std::string(20, '-') << std::endl;


	std::cin >> c;

	int input;
	std::cout << std::string(20, '-') << std::endl;

	/* Npc 목록 호출 */
	getNPCList(begin, end);
	std::cout << std::string(20, '-') << std::endl;
	std::cout << "누구와 거래하시겠습니까? (번호) : ";
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
		// 아직 목록 순서에 대응하는 코드가 없음
		std::cout << "무얼 살까? (앞에 있는 번호를 쓰자)" << std::endl;
		std::cin >> a;
		std::cout << "갯수:";
		std::cin >> howmany;
		std::cout << std::endl;
		deal.Buy(cha, a, howmany);

		break;
	case 's': // sell
		me.printInventory();
		// 아직 목록 순서에 대응하는 코드가 없음
		std::cout << "무얼 팔까? (앞에 있는 번호를 쓰자)" << std::endl;
		std::cin >> a;
		std::cout << "갯수:";
		std::cin >> howmany;
		std::cout << std::endl;
		deal.Sell(cha, a, howmany);

		break;
	default:
		std::cout << "ERR! 잘못된 명령입니다" << std::endl;
		break;
	}
}