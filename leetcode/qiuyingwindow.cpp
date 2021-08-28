#include <iostream>
#include <vector>
#include <set>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    // 定义一个只有两个长度的蚯蚓
    set<int> qiuying;
    // 蚯蚓的初始位置
    int i = 0;
    // 记录蚯蚓爬行过程的长度以及最长可以变多长,haha刚开始为0
    int length;
    int max_length = 0;
    // 蚯蚓开始爬行
    for (int j = 0; j < fruits.size(); j++)
    {
        qiuying.insert(fruits[j]);
        while (qiuying.size() > 2)
        {
            // 蚯蚓当前的长度
            length = j - i;
            max_length = max_length > length ? max_length : length;
            // 蚯蚓的尾部要前进了
            qiuying.erase(fruits[i++]);
        }
        if (qiuying.size() <= 2)
        {
            length = j - i + 1;
            max_length = max_length > length ? max_length : length;
        }
    }
    return max_length;
}

int main()
{
    vector<int> trees = {0, 1, 2, 1};
    cout << totalFruit(trees);
    return 0;
}