#include "player.h"
#include "items.h"

void addItemTo(Character* npc) {
	using namespace ITEM;
	npc->getItem(Apple);
	npc->getItem(WaterBottle);
	npc->getItem(Gum);
}

void initGame() {
	me.setID(-1);

	extern Character cha;

	addItemTo(&cha);
}