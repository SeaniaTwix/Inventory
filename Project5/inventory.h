#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <iostream>
#include <vector>
#include <conio.h>

class Inventory {
public:
	void printInventory();
	void getItem(int itemId);
	void removeItem(int itemId);
	std::vector<std::string> retNameList(int itemCode);
protected:
private:
	std::vector<int> storage;
};
#endif