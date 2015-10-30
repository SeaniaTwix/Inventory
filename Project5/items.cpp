#include "items.h"
#include "inventory.h"
#include <map>

int getItemValue(const int code) {

	std::map<int, int> database;

	using namespace ITEM;

	database.insert(std::make_pair(Apple, 60));
	database.insert(std::make_pair(WaterBottle, 120));
	database.insert(std::make_pair(Hat, 110));
	database.insert(std::make_pair(Shose, 180));
	database.insert(std::make_pair(Socks, 90));
	database.insert(std::make_pair(Gum, 50));

	return database[code];
}

std::string getItemName(int itemNum) {

	std::map<int, std::string> database;

	using namespace ITEM;

	database.insert(std::make_pair(Apple, "Apple"));
	database.insert(std::make_pair(WaterBottle, "Water Bottle"));
	database.insert(std::make_pair(Hat, "Hat"));
	database.insert(std::make_pair(Shose, "Shose"));
	database.insert(std::make_pair(Socks, "Socks"));
	database.insert(std::make_pair(Gum, "Gum"));

	return database[itemNum];
}