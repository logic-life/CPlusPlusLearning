#include <iostream>
#define MAX 4
int main()
{
    const char *aPointerArray[MAX] = {"zhangsan", "lisi", "zhaowu", "hanliu"};
    for (int i = 0; i < MAX; i++)
        std::cout << aPointerArray[i] << std::endl;
    return 0;
}