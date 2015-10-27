#include "inventory.h"
#include "items.h"

void Inventory::printInventory() {
	for (std::vector<int>::const_iterator it = storage.begin(); it != storage.end(); ++it) {
		std::string str = getItemName(storage.at(*it));
		std::cout << *it << ", " << str << std::endl;
	}
}

void Inventory::getItem(int itemId) {
	storage.push_back(itemId);
}

void Inventory::removeItem(int itemId) {
	for (std::vector<int>::iterator it = storage.begin(); it != storage.end();) {
		if (storage.at(*it) == itemId) {
			it = storage.erase(it);
		} else {
			++it;
		}
	}

}
