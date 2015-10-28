#include "deal.h"
#include "items.h"
#include "player.h"

Character me;

// 인자로 받은 itemId를 toWho의 인벤토리에 넣고, 실행한 측의 인벤토리에선 삭제해야 함. 아이템의 가격이 설정된 함수를 불러 toWho의 money에서 빼야함.
// 아이템이나 돈이 없을 경우 예외처리 필요
void Deal::Sell(Character* toWho, int itemId) {
	int price = getPrice(itemId);

	toWho->getItem(itemId);
	me.removeItem(itemId);
	toWho->decMoney(price);
	me.incMoney(price);
}

// 이 함수를 부르기 전에 몇 명의 상대방이 있는지를 보여주고 선택한 상대방이 무슨 아이템을 가지고 있는지 보여줘야 함.
// 아이템이나 돈이 없을 경우 예외처리 필요
void Deal::Buy(Character* byWho, int itemId) {
	int price = getPrice(itemId);

	byWho->removeItem(itemId);
	me.getItem(itemId);
	byWho->incMoney(price);
	me.decMoney(price);
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