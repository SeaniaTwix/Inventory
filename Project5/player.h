#ifndef __PLAYER_H__
#define __PLAYER_H__
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
#endif