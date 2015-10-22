#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
//#include "player.h"
#include "npc.h"

class Inventory {
public:
	void getItem(int itemId);
	void removeItem(int itemId);
protected:
private:
	//int nInit = 0;
	std::vector<int> storage;
	std::vector<int> getInvList();
};