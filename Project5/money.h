#pragma once
#include "character.h"

class Money {
public:
	void incMoney(int moneyValue);
	void decMoney(int moneyValue);
protected:
	int money;
private:
};