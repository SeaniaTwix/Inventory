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


	// ������� �ϴ� �������� �ڵ尡 storage�� �ְ�, ��������ϴ� �������� ������ ���� �����ϴ� ���� ��ŭ ������ ���
	// vector�� �����ϴ� ItemType ��Ҹ� ����
	if (itemId == (*finder).itemCode && howMany == (*finder).howMany) {
		this->storage.erase(std::remove_if(	this->storage.begin(), 
											this->storage.end(), 
											[itemId](ItemType const& itemTy) { return itemTy.itemCode == itemId; }),
			this->storage.end());
	// ������ �ٸ��ٸ�
	} else if (itemId == (*finder).itemCode) {
		// ���� ��û ������ ������ �ִ� �ͺ��� ���ٸ�
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