#pragma once
#include "inventory.h"
#include "money.h"
#include "character.h"

Player me;

class Player : public Character {
public:
	Player(int thisId) {
		thisId = -1;
	}
	//int playerMoney;
private:
	int thisId;
};
