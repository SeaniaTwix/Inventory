#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "character.h"

#define __QUIT__ 0

class NPC;

void getInputState(NPC* cha);

// me (�÷��̾� �ڽ�)�� �����ϱ� ������ ���� ó��.
extern Character me;

#endif