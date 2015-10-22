#pragma once
#include <vector>
#include <string>
#include "system.h"
#include "inventory.h"
#include "system.h"

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
	chara.push_back(this->thisId);
}

Character::~Character() {
}