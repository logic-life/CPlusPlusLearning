#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isBig(int x, int y);
int main(void)
{

    vector<int> vec = {1, 22, 55, 6, 4, 8};
    sort(vec.begin(), vec.end());
    for (auto i : vec)
        cout << i;
    // sort(vec.begin(), vec.end(), isBig);
    //相同效果
    sort(vec.begin(), vec.end(), [](int x, int y) { return x > y; });
    for (auto i : vec)
        cout << i;
    return 0;
}

bool isBig(int x, int y)
{
    //前者比后者小，对应升序排列
    if (x > y)
        return true;
    return false;
}