#pragma once
#include <Windows.h>
#include <vector>
#include "character.h"

typedef enum {
	OUTGOINGS,
	INCOME
} UseType;

void initScreen();

namespace CHARALIST {
	extern std::vector<int> chara;
}

extern Character me(-1);