#pragma once
#include <Windows.h>
#include <vector>
#include "character.h"

typedef enum {
	OUTGOINGS,
	INCOME
} UseType;

void initScreen();

extern std::vector<int> chara;
// me (플레이어 자신)은 유일하기 때문에 전역 처리.