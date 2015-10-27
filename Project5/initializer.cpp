#include "npc.h"
#include "items.h"

std::map<int, std::string> NPCList;

void addItemTo(Character* npc) {
	using namespace ITEM;
	npc->getItem(Apple);
	npc->getItem(WaterBottle);
	npc->getItem(Gum);
}

NPC initGame() {
	me.setID(-1);

	NPC cha(0);
	addItemTo(&cha);

	return cha;
}