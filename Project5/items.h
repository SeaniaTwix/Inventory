#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>

std::string getItemName(int itemNum);
struct Item;

namespace ITEM {
	enum ITEMS {
		Apple,
		WaterBottle,
		Hat,
		Shose,
		Socks,
		Gum
	};
}
#endif