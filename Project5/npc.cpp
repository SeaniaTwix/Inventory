#include "npc.h"
#include "system.h"
#include <map>

std::map<int, std::string> nameList();

//
//std::string NPC::Name(int npcId) {
//	return nameList()[npcId];
//}

std::vector<int> getNpcList() {
	using namespace CHARALIST;
	return chara;
}

// ��� Npc�� �ڵ� ��ȣ, �̸��� ���ʴ�� ǥ���Ѵ�.
void showNpcNameList() {
	std::map<int, std::string>::iterator it;

	for (it = nameList().begin(); it != nameList().end(); ++it) {
		std::cout << (*it).first << ". " << (*it).second << std::endl;
	}
}