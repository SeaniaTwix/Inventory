#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "character.h"

#define __QUIT__ 0

class NPC;

void getInputState(NPC cha);
//void showNpcNameList();

extern Character me;

//class Player : public Character {
//public:
//	Player() {
//		thisId = -1;
//	}
//	//int playerMoney;
//protected:
//	int thisId;
//private:
//};

#endif