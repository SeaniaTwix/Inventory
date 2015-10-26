#include "npc.h"
#include <map>

extern std::map<int, std::string> NPCList;
auto i = 0;

std::string nameList(int n) {
	std::vector<std::string> strv;

	//strv.insert(std::make_pair(-1, "You"));
	strv.push_back("Bob");
	strv.push_back("Nasha");
	strv.push_back("Roarly");
	strv.push_back("John");

	return strv[n];
}

NPC::NPC(int setNpcId) {
	this->setID(setNpcId);
	auto thisNPCID = this->retID();
	NPCList.insert(std::make_pair(i, nameList(setNpcId)));
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
