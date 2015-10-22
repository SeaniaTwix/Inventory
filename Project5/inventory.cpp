#include "inventory.h"
#include "items.h"

void Inventory::getItem(int itemId) {
	storage.push_back(itemId);
}

void Inventory::removeItem(int itemId) {
	std::vector<int> list = getInvList();

	for (std::vector<int>::iterator it = list.begin(); it != list.end();) {
		if (list.at(*it) == itemId) {
			it = list.erase(it);
		} else {
			++it;
		}
	}

}

std::vector<int> Inventory::getInvList() {
	std::vector<int> list;
	
	for (auto i = 0; i <= storage.size(); ++i) {
		list.push_back(storage.at(i));
	}
	
	return list;
}
