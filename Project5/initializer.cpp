#include "npc.h"
#include "items.h"

void addItemTo(Character* npc) {
	using namespace ITEM;
	npc->getItem(Apple);
	npc->getItem(WaterBottle);
	npc->getItem(Gum);
}
