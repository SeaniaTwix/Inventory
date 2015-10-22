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

// 모든 Npc의 코드 번호, 이름을 차례대로 표시한다.
void showNpcNameList() {
	std::map<int, std::string>::iterator it;

	for (it = nameList().begin(); it != nameList().end(); ++it) {
		std::cout << (*it).first << ". " << (*it).second << std::endl;
	}
}