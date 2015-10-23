#pragma once
#include "inventory.h"
#include "money.h"

class Player : public Character {
public:
	Player(int thisId) {
		thisId = -1;
	}
	//int playerMoney;
private:
	int thisId;
};
