#include "money.h"
#include "character.h"
#include "player.h"

//////////////////////////////////////////////////////////////////////////
//////						증가 값, 대상								//////
//////////////////////////////////////////////////////////////////////////
void Money::incMoney(int moneyValue) {
	this->money += moneyValue;
/*
	if (Who.retID() != me.thisId) {
		me.wallet(INCOME, moneyValue);
	} else {
		Who.wallet(INCOME, moneyValue);
	}*/
}

//////////////////////////////////////////////////////////////////////////
//////						감소 값, 대상								//////
//////////////////////////////////////////////////////////////////////////
void Money::decMoney(int moneyValue) {
	this->money -= moneyValue;
	/*if (Who.retID() != me.thisId) {
		me.wallet(OUTGOINGS, moneyValue);
	} else {
		Who.wallet(OUTGOINGS, moneyValue);
	}*/
}