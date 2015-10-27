#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <vector>
#include <string>
#include <map>
#include "system.h"
#include "inventory.h"
#include "money.h"

std::string nameList();

typedef enum {
	OUTGOINGS,
	INCOME
} UseType;

class Character : public Inventory, public Money {
public:
	//Character();
	//~Character();
	std::string name;
	void wallet(UseType type, int aMoney);
	void setID(int id);
	int retID();
protected:
private:
	int thisId;
	//std::vector<int> storage;
	//int money;
};

//Character::Character() {
//}
//
//Character::~Character() {
//}
#endif