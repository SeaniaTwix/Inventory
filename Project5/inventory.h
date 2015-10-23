#pragma once
#include <iostream>
#include <vector>
#include <conio.h>

class Inventory {
public:
	void printInventory();
	void getItem(int itemId);
	void removeItem(int itemId);
protected:
private:
	std::vector<int> storage;
	//int nInit = 0;
	//std::vector<int> getInvList();
};