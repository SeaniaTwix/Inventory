#include "items.h"

std::string getItemName(int itemNum) {
	using namespace ITEM;
	switch (itemNum) {
	case Apple:
		return "Apple";
		break;
	case WaterBottle:
		return "WaterBottle";
		break;
	default:
		return "(err)";
		break;
	}
}