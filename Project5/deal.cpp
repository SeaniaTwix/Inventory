#include "deal.h"
#include "items.h"
#include "player.h"

bool checkMoneyForDeal(const int itemCode, const int haveMoney) {
	if (haveMoney >= getItemValue(itemCode)) {
		return true;
	} else {
		return false;
	}
}

Character me;

// ���ڷ� ���� itemId�� toWho�� �κ��丮�� �ְ�, ������ ���� �κ��丮���� �����ؾ� ��. �������� ������ ������ �Լ��� �ҷ� toWho�� money���� ������.
// �������̳� ���� ���� ��� ����ó�� �ʿ�
void Deal::Sell(Character* toWho, int itemId, int howMany) {
	int price = getItemValue(itemId);

	if (checkMoneyForDeal(itemId, toWho->wallet(CHECK))){
		toWho->getItem(itemId, howMany);
		me.removeItem(itemId, howMany);
		toWho->decMoney(price);
		me.incMoney(price);
	}
}

// �� �Լ��� �θ��� ���� �� ���� ������ �ִ����� �����ְ� ������ ������ ���� �������� ������ �ִ��� ������� ��.
// �������̳� ���� ���� ��� ����ó�� �ʿ�
void Deal::Buy(Character* byWho, int itemId, int howMany) {
	int price = getItemValue(itemId);

	if (checkMoneyForDeal(itemId, me.wallet(CHECK))) {
		byWho->removeItem(itemId, howMany);
		me.getItem(itemId, howMany);
		byWho->incMoney(price);
		me.decMoney(price);
	}
}

// ���߿� map���� �� �������� ������ ������ �������� ���� ��. �� �ڿ� ��ü������ �̸��� ����
//int Deal::getPrice(int itemId) {
//	using namespace ITEM;
//
//	switch (itemId) {
//	case Apple:
//		return 100;
//	case WaterBottle:
//		return 250;
//	case Hat:
//		return 400;
//	case Shose:
//		return 300;
//	case Socks:
//		return 180;
//	case Gum:
//		return 30;
//	default:
//		return 0;
//	}
//}