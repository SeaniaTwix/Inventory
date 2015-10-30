#include "items.h"
#include "inventory.h"
#include <map>

int getItemValue(const int code) {

	std::map<int, int> database;

	database.insert(std::make_pair(0, 100));
	database.insert(std::make_pair(1, 120));
	database.insert(std::make_pair(2, 110));
	database.insert(std::make_pair(3, 130));

	return database[code];
}

std::string getItemName(int itemNum) {
	using namespace ITEM;
	switch (itemNum) {
	case Apple:
		return "Apple";
		break;
	case WaterBottle:
		return "WaterBottle";
		break;
	case Hat:
		return "Hat";
		break;
	case Shose:
		return "Shose";
		break;
	case Socks:
		return "Socks";
		break;
	case Gum:
		return "Gum";
		break;
	default:
		return "(err)";
		break;
	}
}