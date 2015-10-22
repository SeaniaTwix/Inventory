#pragma once
#include "character.h"

class Deal {
public:
	void Sell(int toWho, int itemId);
	void Buy(int byWho, int itemId);
	int getPrice(int itemId);
private:

};