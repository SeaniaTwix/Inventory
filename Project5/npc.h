#ifndef npc_h__
#define npc_h__

#include "player.h"

std::string nameList(int n);
//std::map<int, std::string> NPCList;
void getNPCList(std::map<int, std::string>::iterator begin, std::map<int, std::string>::iterator end);

class NPC : public Character {
public:
	NPC(int setNpcId);
	~NPC();
};
#endif // npc_h__
