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

/*

	InvIterator finder = this->inventoryFinder(itemId);

	if (finder == this->storage.end()) {
		ItemType tempItem;
		tempItem.itemName = getItemName(itemId);
		tempItem.itemCode = itemId;
		tempItem.howMany = howMany;

		this->storage.push_back(tempItem);

	} else {
		(*finder).howMany += howMany;
	}*/
}

void Inventory::removeItem(int itemId, unsigned int howMany) {
	//for (vb = storage.begin(); vb != ve;) {
	//	if (Inventory::storage.at(*vb) == itemId) {
	//		vb = Inventory::storage.erase(vb);
	//	} else {
	//		++vb;
	//	}
	//}


	InvIterator finder = this->inventoryFinder(itemId);


	// ������� �ϴ� �������� �ڵ尡 storage�� �ְ�, ��������ϴ� �������� ������ ���� �����ϴ� ���� ��ŭ ������ ���
	// vector�� �����ϴ� ItemType ��Ҹ� ����
	if (itemId == (*finder).itemCode && howMany == (*finder).howMany) {
		//std::remove(this->storage.begin(), this->storage.end(), finder);

		std::remove(this->storage.begin());

		std::remove(this->storage.end(), finder);



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
	//for (/*vb = storage.begin()*/; vb != ve; ++vb) {
	//	std::string str = getItemName(Inventory::storage.at(vb));
	//	std::cout /*<< ������ �ڵ� �־���� �ϴ� ��*/ << ", " << str << std::endl;
	//	std::cout << (&vb) << std::endl;
	//}

	for (InvIterator i = this->storage.begin(); i != this->storage.end(); ++i) {
		std::cout << (*i).itemName << " of " << (*i).howMany << std::endl;
	}

}

//std::vector<std::string> Inventory::retNameList(int itemCode) {
//	std::vector<std::string> vlist;
//
//	vlist.push_back("Apple");
//	vlist.push_back("Water Bottle");
//	vlist.push_back("Hat");
//	vlist.push_back("Shose");
//	vlist.push_back("Socks");
//	vlist.push_back("Gum");
//	return vlist;
//}
//
