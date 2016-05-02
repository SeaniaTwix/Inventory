#include <map>
#include <iostream>
#include "npc.h"

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

int Character::wallet(UseType type) {
	if (type == CHECK) {
		return this->money;
	} else {
		//Error
		std::cerr << "Error! Argument not matched!" << std::endl;
		_getwch();
		exit(EXIT_FAILURE);
	}
}

void Character::setID(int id) {
	this->thisId = id;
}

int Character::retID() {
	return this->thisId;
}

