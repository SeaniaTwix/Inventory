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
// me (�÷��̾� �ڽ�)�� �����ϱ� ������ ���� ó��.