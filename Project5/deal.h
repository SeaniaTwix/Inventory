#ifndef __DEAL_H__
#define __DEAL_H__
#include "character.h"

class Deal {
public:
	void Sell(Character* toWho, int itemId, int howMany);
	void Buy(Character* byWho, int itemId, int howMany);
private:

};
#endif