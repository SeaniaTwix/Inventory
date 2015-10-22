#include "money.h"
#include "character.h"

class Character;

//////////////////////////////////////////////////////////////////////////
//////						���� ��, ���								//////
//////////////////////////////////////////////////////////////////////////
void Money::incMoney(int moneyValue, int Who) {

	if (Who == -1) {
		me.wallet(INCOME, moneyValue);
	} else {
		Character cha(Who);
		cha.wallet(INCOME, moneyValue);
	}
}

//////////////////////////////////////////////////////////////////////////
//////						���� ��, ���								//////
//////////////////////////////////////////////////////////////////////////
void Money::decMoney(int moneyValue, int Who) {

	if (Who == -1) {
		Character me(-1);
		me.wallet(OUTGOINGS, moneyValue);
	} else {
		Character cha(Who);
		cha.wallet(OUTGOINGS, moneyValue);
	}
}