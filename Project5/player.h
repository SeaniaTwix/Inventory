#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "character.h"

#define __QUIT__ 0

class NPC;

void getInputState(NPC* cha);

// me (플레이어 자신)은 유일하기 때문에 전역 처리.
extern Character me;

#endif