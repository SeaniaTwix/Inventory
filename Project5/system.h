#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <Windows.h>
#include <vector>
#include "character.h"



void initScreen();

extern std::vector<int> chara;
// me (플레이어 자신)은 유일하기 때문에 전역 처리.
#endif