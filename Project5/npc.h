#pragma once
#include <string>
#include "inventory.h"

class NPC : public Inventory {
public:
	NPC(int aNpcId) {
		npcId = aNpcId;
	}
	//std::string Name(int npcId);
	int npcMoney;
private:
	int npcId;
	std::string npcName;
};