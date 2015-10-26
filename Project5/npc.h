#pragma once
#include "player.h"

std::string nameList(int n);
void getNPCList(std::map<int, std::string>::iterator begin, std::map<int, std::string>::iterator end);

class NPC : protected Character {
public:
	NPC(int setNpcId);
	~NPC();
};
