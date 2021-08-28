#include "_52rand.h"

int main(int argc, char *argv[])
{
    randPlayingCard();
    std::cout << "内部数组空间为：" << std::endl;
    for (auto i : playing_card_value)
        std::cout << i << " ";

    depatchCard();
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
        for (int j = 1; j <= 13; j++)
        {
            std::cout << player_role[i][j] << " ";
        }
    return 0;
}