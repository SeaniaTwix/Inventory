#include "deal.h"
#include "items.h"
#include "money.h"
#include "inventory.h"
#include "system.h"
//#include "npc.h"

// 인자로 받은 itemId를 toWho의 인벤토리에 넣고, 실행한 측의 인벤토리에선 삭제해야 함. 아이템의 가격이 설정된 함수를 불러 toWho의 money에서 빼야함.
void Deal::Sell(int toWho, int itemId) {
	int price = getPrice(itemId);
	me.wallet(INCOME, price);

	getItem(itemId);
	me.removeItem(itemId);
}

// 이 함수를 부르면 몇 명의 상대방이 있는지를 보여주고 선택한 상대방이 무슨 아이템을 가지고 있는지 보여줘야 함.
void Deal::Buy(int byWho, int itemId) {
	int price = getPrice(itemId);
	me.wallet(OUTGOINGS, price);

	byWho.removeItem(itemId);
	me.getItem(itemId);
}

// 나중엔 map으로 각 아이템의 가격을 데이터 형식으로 만들 것. 그 뒤엔 자체적으로 이름값 리턴
int Deal::getPrice(int itemId) {
	using namespace ITEM;

	switch (itemId) {
	case Apple:
		return 100;
	case WaterBottle:
		return 250;
	case Hat:
		return 400;
	case Shose:
		return 300;
	case Socks:
		return 180;
	case Gum:
		return 30;
	default:
		return 0;
	}
}