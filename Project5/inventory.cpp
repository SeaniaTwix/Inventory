#include "inventory.h"
#include "items.h"


Inventory::Inventory() {
	vb = storage.begin();
	ve = storage.end();
}

Inventory::~Inventory() {
}

void Inventory::printInventory(std::vector<int>::iterator beg, std::vector<int>::iterator end) {
	for (; beg != end; ++beg) {
		std::string str = getItemName(Inventory::storage.at(*beg));
		std::cout << *beg << ", " << str << std::endl;
	}
}

void Inventory::getItem(int itemId) {
	Inventory::storage.push_back(itemId);
}

void Inventory::removeItem(int itemId) {
	for (std::vector<int>::iterator it = Inventory::storage.begin(); it != Inventory::storage.end();) {
		if (Inventory::storage.at(*it) == itemId) {
			it = Inventory::storage.erase(it);
		} else {
			++it;
		}
	}

}

std::vector<std::string> Inventory::retNameList(int itemCode) {
	std::vector<std::string> vlist;

	vlist.push_back("Apple");
	vlist.push_back("Water Bottle");
	vlist.push_back("Hat");
	vlist.push_back("Shose");
	vlist.push_back("Socks");
	vlist.push_back("Gum");
	return vlist;
}

