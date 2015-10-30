#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>

std::string getItemName(int itemNum);
int getItemValue(const int code);

//struct ItemType;

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
//
//// item { itemName, itemCode }
//struct ItemType {
//	std::string itemName;
//	int itemCode;
//	unsigned int howMany;
//};

#endif