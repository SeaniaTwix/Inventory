#include "deal.h"
#include "items.h"
#include "money.h"
#include "inventory.h"
#include "system.h"
#include "player.h"

// ���ڷ� ���� itemId�� toWho�� �κ��丮�� �ְ�, ������ ���� �κ��丮���� �����ؾ� ��. �������� ������ ������ �Լ��� �ҷ� toWho�� money���� ������.
void Deal::Sell(Character* toWho, int itemId) {

	Money money;

	int price = getPrice(itemId);
	/*me.wallet(INCOME, price);

	getItem(itemId);
	me.removeItem(itemId);*/

	toWho->getItem(itemId);
	me.removeItem(itemId);
	toWho->decMoney(price);
	me.incMoney(price);
}

// �� �Լ��� �θ��� �� ���� ������ �ִ����� �����ְ� ������ ������ ���� �������� ������ �ִ��� ������� ��.
void Deal::Buy(Character* byWho, int itemId) {

	Money money;

	int price = getPrice(itemId);
	//me.wallet(OUTGOINGS, price);
	//byWho.removeItem(itemId);
	//me.getItem(itemId);

	byWho->removeItem(itemId);
	me.getItem(itemId);
	byWho->incMoney(price);
	me.decMoney(price);
}

// ���߿� map���� �� �������� ������ ������ �������� ���� ��. �� �ڿ� ��ü������ �̸��� ����
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