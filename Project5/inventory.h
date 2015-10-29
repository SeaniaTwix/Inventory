#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <iostream>
#include <vector>
#include <conio.h>
#include "items.h"

// item { itemName, itemCode, howMany }
struct ItemType {
	std::string itemName;
	int itemCode;
	unsigned int howMany;
};

typedef std::vector<ItemType>::iterator InvIterator;

class Inventory {
public:
	Inventory();
	~Inventory();
	InvIterator inventoryFinder(int codeToFind);
	void printInventory();
	void getItem(int itemId, unsigned int howMany);
	void removeItem(int itemId, unsigned int howMany);

protected:
private:
	std::vector<ItemType> storage;
};

#endif