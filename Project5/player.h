#pragma once
#include "money.h"
#include "character.h"

class Player : public Character {
public:
	Player(int thisId) {
		thisId = -1;
	}
	//int playerMoney;
private:
	int thisId;
};
