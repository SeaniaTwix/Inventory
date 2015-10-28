#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <iostream>
#include <forward_list>
#include <vector>
#include <conio.h>
#include "items.h"

class Inventory {
public:
	Inventory();
	~Inventory();
	void printInventory(std::forward_list<Item> &flist);
	void getItem(int itemId);
	void removeItem(int itemId);
	std::vector<std::string> retNameList(int itemCode);
protected:
private:

	Item item;
	std::forward_list<Item> storage;
	std::forward_list<Item>::iterator vb, ve;
};
#endif