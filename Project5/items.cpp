#include "items.h"
#include "inventory.h"
#include <map>

int getItemValue(const int code) {

	std::map<int, int> database;

	using namespace ITEM;

	database.insert(std::make_pair(Apple, 100));
	database.insert(std::make_pair(WaterBottle, 120));
	database.insert(std::make_pair(Hat, 110));
	database.insert(std::make_pair(Shose, 130));
	database.insert(std::make_pair(Socks, 150));
	database.insert(std::make_pair(Gum, 50));

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