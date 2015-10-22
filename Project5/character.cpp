#include <map>
#include <iostream>
#include "character.h"

std::map<int, std::string> nameList();

void Character::wallet(UseType type, int aMoney) {
	if (type == OUTGOINGS) {
		this->money -= aMoney;
	} else if (type == INCOME) {
		this->money += aMoney;
	} else {
		//Error
		std::cerr << "Error" << std::endl;
		_getwch();
		exit(EXIT_FAILURE);
	}
}

std::string Character::nameCard(int aId) {
	return nameList()[aId];
}

std::map<int, std::string> nameList() {
	std::map<int, std::string> strv;

	strv.insert(std::make_pair(-1, "Player"));
	strv.insert(std::make_pair(0, "Bob"));
	strv.insert(std::make_pair(1, "Cat"));

	return strv;
}