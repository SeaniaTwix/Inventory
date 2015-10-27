#include "npc.h"
#include <list>
#include <random>

extern std::map<int, std::string> NPCList;
auto i = 0;

std::string nameList() {
	std::vector<std::string> lList;

	lList.push_back("Bob");
	lList.push_back("Nasha");
	lList.push_back("Roarly");
	lList.push_back("Renard");
	lList.push_back("John");
	lList.push_back("Ren");

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, (int)(lList.size()));
	int dice = dist(gen);

	return lList[dice];
}

NPC::NPC(int setNpcId) {
	this->setID(setNpcId);
	auto thisNPCID = this->retID();
	NPCList.insert(std::make_pair(i, nameList()));
	this->name = nameList();
	i++;

	//* test
	std::cout << "NPC Constructed. ID:" << this->retID() << std::endl;
	std::cout << "Name: " << this->name << std::endl;
	//*/
}

// For Dummy NPC
NPC::NPC() {
	this->setID(-1);
	auto thisNPCID = this->retID();
	NPCList.insert(std::make_pair(i, nameList()));
	this->name = nameList();
	i++;
}

NPC::~NPC() {
	//* test
	std::cout << "NPC Destructed. ID:" << this->retID() << std::endl;
	//*/
}

void getNPCList(std::map<int, std::string>::iterator begin, std::map<int, std::string>::iterator end) {
	for (;begin != end;++begin) {
		std::cout << (*begin).first << ", ";
		std::cout << (*begin).second << std::endl;
	}
}
