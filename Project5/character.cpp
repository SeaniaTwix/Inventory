#include <map>
#include <iostream>
#include "npc.h"

//std::map<int, std::string> nameList();

// ���ǽ� ��� �ڷ� ���ϱ�
//std::vector<int> getNpcList() {
//	using namespace CHARALIST;
//	return chara;
//}

// ���ǽ� ��� ���ϱ�
//void showNpcNameList(std::map<int, std::string>::iterator begin, std::map<int, std::string>::iterator end) {
//	for (;begin != end;++begin) {
//		std::cout << (*begin).first;
//		std::cout << (*begin).second << std::endl;
//	}
//}

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

void Character::setID(int id) {
	this->thisId = id;
}

int Character::retID() {
	return this->thisId;
}

std::string Character::nameCard(int aId) {
	return nameList(this->thisId);
}

