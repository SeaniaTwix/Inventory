#pragma once
#include <vector>
#include <string>
#include "system.h"
#include "inventory.h"

class Character : public Inventory {
public:
	Character(int aId);
	~Character();
	std::string name;
	void wallet(UseType type, int aMoney);
	std::string nameCard(int thisId);
private:
	int money;
	int thisId;
	//std::vector<int> storage;
};

Character::Character(int aId) {
	thisId = aId;
	{ using namespace CHARALIST;
	chara.push_back(thisId);
	}
}

Character::~Character() {
}