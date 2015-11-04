#include "deal.h"
#include "items.h"
#include "player.h"

bool checkMoneyForDeal(const int itemValue, const int haveMoney) {
	if (haveMoney >= itemValue) {
		return true;
	} else {
		return false;
	}
}

Character me;

// 인자로 받은 itemId를 toWho의 인벤토리에 넣고, 실행한 측의 인벤토리에선 삭제해야 함. 아이템의 가격이 설정된 함수를 불러 toWho의 money에서 빼야함.
// 아이템이나 돈이 없을 경우 예외처리 필요
void Deal::Sell(Character* toWho, int itemId, int howMany) {
	int price = getItemValue(itemId);

	if (checkMoneyForDeal(price, toWho->wallet(CHECK))){
		toWho->getItem(itemId, howMany);
		me.removeItem(itemId, howMany);
		toWho->decMoney(price);
		me.incMoney(price);
	}
}

// 이 함수를 부르기 전에 몇 명의 상대방이 있는지를 보여주고 선택한 상대방이 무슨 아이템을 가지고 있는지 보여줘야 함.
// 아이템이나 돈이 없을 경우 예외처리 필요
void Deal::Buy(Character* byWho, int itemId, int howMany) {
	int price = getItemValue(itemId) * howMany;

	if (checkMoneyForDeal(price, me.wallet(CHECK))) {
		byWho->removeItem(itemId, howMany);
		me.getItem(itemId, howMany);
		byWho->incMoney(price);
		me.decMoney(price);
	}
}
