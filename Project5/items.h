#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>

std::string getItemName(int itemNum);

namespace ITEM {
	enum ITEMS {
		Apple = 100,
		WaterBottle,
		Hat,
		Shose,
		Socks,
		Gum
	};
}
#endif