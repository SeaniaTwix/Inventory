#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <vector>
#include <string>
#include <map>
#include "system.h"
#include "inventory.h"
#include "money.h"

//std::map<int, std::string> nameList();
//void showNpcNameList(std::map<int, std::string>::iterator begin, std::map<int, std::string>::iterator end);

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
	std::string nameCard(int thisId);
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