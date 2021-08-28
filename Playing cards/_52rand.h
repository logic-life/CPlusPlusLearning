#ifndef _52_RAND_H
#define _52_RAND_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
//生成1到52之间整数的随机数
extern unsigned int playing_card_value[53];
//四个玩家对应的手牌，其中两位玩家各多一张手牌
extern unsigned int player_role[4][15];
unsigned int rand1_52(void);

//初始化扑克牌
void createCard(void);
//随机生成扑克牌
void randPlayingCard(void);

void depatchCard(void);

#endif //_51_RAND_H