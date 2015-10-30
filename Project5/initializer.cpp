#include "npc.h"
#include "items.h"

void addItemTo(NPC* npc) {
	using namespace ITEM;
	npc->getItem(Apple, 10);
	npc->getItem(WaterBottle, 10);
	npc->getItem(Gum, 10);

	me.incMoney(5000);
	npc->incMoney(5000);
}
