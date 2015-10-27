#include "inventory.h"
#include "items.h"

void Inventory::printInventory() {
	for (std::vector<int>::iterator it = Inventory::storage.begin(); it != Inventory::storage.end(); ++it) {
		std::string str = getItemName(Inventory::storage.at(*it));
		std::cout << *it << ", " << str << std::endl;
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
