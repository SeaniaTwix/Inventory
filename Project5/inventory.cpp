#include "inventory.h"
#include "items.h"
#include <algorithm>

Inventory::Inventory() {
	vb = storage.begin();
	ve = storage.end();
}

Inventory::~Inventory() {
}

void Inventory::printInventory(std::forward_list<Item> &flist) {

	//for (/*vb = storage.begin()*/; vb != ve; ++vb) {
	//	std::string str = getItemName(Inventory::storage.at(vb));
	//	std::cout /*<< 아이템 코드 넣어줘야 하는 곳*/ << ", " << str << std::endl;
	//	std::cout << (&vb) << std::endl;
	//}

	
}

void Inventory::getItem(int itemId) {
	Item &it = item;
	
	storage.push_front(it);
	auto now = storage.begin();

	(&now).itemCode = itemId;
	
}

void Inventory::removeItem(int itemId) {

	//for (vb = storage.begin(); vb != ve;) {
	//	if (Inventory::storage.at(*vb) == itemId) {
	//		vb = Inventory::storage.erase(vb);
	//	} else {
	//		++vb;
	//	}
	//}

	//vb = storage.begin();

	std::remove_if(vb, ve, itemId);
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

