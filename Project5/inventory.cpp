#include "inventory.h"
#include <algorithm>

Inventory::Inventory() {
}

Inventory::~Inventory() {
}

bool operator==(const ItemType &Left, const ItemType &Right) {
	return Left.itemCode == Right.itemCode;
}

bool operator==(const ItemType &Left, const int &Right) {
	return Left.itemCode == Right;
}

bool operator==(const int &Left, const ItemType &Right) {
	return Left == Right.itemCode;
}

void Inventory::getItem(int itemId, unsigned int howMany) {
	InvIterator finder = this->inventoryFinder(itemId);

	if (finder == this->storage.end()) {
		ItemType tempItem;
		tempItem.itemName = getItemName(itemId);
		tempItem.itemCode = itemId;
		tempItem.howMany = howMany;

		this->storage.push_back(tempItem);

	} else {
		(*finder).howMany += howMany;
	}
}

void Inventory::removeItem(int itemId, unsigned int howMany) {
	InvIterator finder = this->inventoryFinder(itemId);


	// 지우고자 하는 아이템의 코드가 storage에 있고, 지우고자하는 아이템의 갯수가 현재 존재하는 갯수 만큼 존재할 경우
	// vector에 존재하는 ItemType 요소를 지움
	if (itemId == (*finder).itemCode && howMany == (*finder).howMany) {
		this->storage.erase(std::remove_if(	this->storage.begin(), 
											this->storage.end(), 
											[itemId](ItemType const& itemTy) { return itemTy.itemCode == itemId; }),
			this->storage.end());
	// 갯수만 다르다면
	} else if (itemId == (*finder).itemCode) {
		// 삭제 요청 갯수가 가지고 있는 것보다 많다면
		if ((*finder).howMany <= howMany) {
			std::cout << "ERROR" << std::endl;
		} else {
			(*finder).howMany -= howMany;
		}
	}
}

InvIterator Inventory::inventoryFinder(int codeToFind) {
	return std::find(this->storage.begin(), this->storage.end(), codeToFind);
}

void Inventory::printInventory() {
	int num = 0;

	for (InvIterator i = this->storage.begin(); i != this->storage.end(); ++i) {
		std::cout << '(' <<(*i).itemCode << ')' 
			<< (*i).itemName << " of " 
			<< (*i).howMany << "(price:" 
			<< getItemValue((*i).itemCode) 
			<< ')' << std::endl;
	}
}