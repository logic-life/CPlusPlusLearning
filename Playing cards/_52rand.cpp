#include "_52rand.h"
using namespace std;

//存储已经生成的扑克牌
unsigned int playing_card_value[53];
//四个玩家对应的手牌，其中两位玩家各多一张手牌
unsigned int player_role[4][15];
typedef enum
{ //扑克排中的非大小王所有排列
    TWO,
    TREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGTH,
    NINE,
    TEN,
    J,
    Q,
    K,
    A
} POKER_RANGE;

typedef enum
{
    CLUBS,    //梅花
    SPADES,   //黑桃
    DIAMONDS, //方块
    HEARTS    //红桃
} COLOR;

unsigned rand1_52(void)
{
    double _d = (double)rand() / ((double)RAND_MAX + 1.0);
    return (1 + (int)(_d * (52)));
}
//游戏初始化
void createCard()
{
    //初始化，置当前所有扑克牌未生成
    std::fill(playing_card_value, playing_card_value + 52, 0);
    for (int i = 1; i <= 52; i++)
        playing_card_value[i] = i;
    srand((int)time(0));
}

//洗牌
void randPlayingCard(void)
{
    createCard();
    unsigned int position = 0;
    for (int i = 1; i <= 26; i++)
    {
        position = rand1_52();
        if (position != i)
            swap(playing_card_value[i], playing_card_value[position]);
    }
    return;
}

//发牌
void depatchCard(void)
{
    int m = 1;
    for (int i = 0; i < 4; i++)
        for (int j = 1; j <= 13; j++)
        {
            if (m == 53)
            {
                perror("out of the range of card");
                exit(1);
            }
            player_role[i][j] = playing_card_value[m++];
        }
}
