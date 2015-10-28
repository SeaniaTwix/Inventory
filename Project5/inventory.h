#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <iostream>
#include <vector>
#include <conio.h>

class Inventory {
public:
	Inventory();
	~Inventory();
	void printInventory(std::vector<int>::iterator beg, std::vector<int>::iterator end);
	void getItem(int itemId);
	void removeItem(int itemId);

	std::vector<int>::iterator vb, ve;
	std::vector<std::string> retNameList(int itemCode);
protected:
private:
	std::vector<int> storage;
};
#endif