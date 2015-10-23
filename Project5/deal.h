#pragma once
#include "character.h"

class Deal {
public:
	void Sell(Character* toWho, int itemId);
	void Buy(Character* byWho, int itemId);
	int getPrice(int itemId);
private:

};