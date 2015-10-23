#pragma once
#include <vector>
#include <string>
#include "system.h"
#include "inventory.h"
#include "system.h"
#include "money.h"

typedef enum {
	OUTGOINGS,
	INCOME
} UseType;

class Character : public Inventory, public Money {
public:
	Character();
	~Character();
	std::string name;
	void wallet(UseType type, int aMoney);
	void setID(int id);
	int retID();
	std::string nameCard(int thisId);
private:
	//int money;
	int thisId;
	//std::vector<int> storage;
};

Character::Character() {
}

Character::~Character() {
}