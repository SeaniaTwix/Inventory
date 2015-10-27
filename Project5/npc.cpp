#include "npc.h"

std::map<int, std::string> NPCList;
auto i = 0;

std::string nameList(int n) {

	//strv.insert(std::make_pair(-1, "You"));
	NPCList.insert(std::make_pair(0, "Bob"));
	NPCList.insert(std::make_pair(1, "Nasha"));
	NPCList.insert(std::make_pair(2, "Roarly"));
	NPCList.insert(std::make_pair(3, "John"));

	// iterator of NPCList(n)
	auto it = NPCList.find(n);

	return (*it).second;
}

NPC::NPC(int setNpcId) {
	this->setID(setNpcId);
	auto thisNPCID = this->retID();
	NPCList.insert(std::make_pair(i, nameList(thisNPCID)));
	i++;

}

NPC::~NPC() {
}

void getNPCList(std::map<int, std::string>::iterator begin, std::map<int, std::string>::iterator end) {
	for (;begin != end;++begin) {
		std::cout << (*begin).first;
		std::cout << (*begin).second << std::endl;
	}
}
