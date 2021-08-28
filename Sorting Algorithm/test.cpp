#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char *argv[])
{
    //定义一个字符串
    string str;
    //     //待查找字符
    char aim_str;
    getline(cin, str);
    cin >> aim_str;
    int count = 0;
    for (auto i : str)
    {
        if (tolower(i) == tolower(aim_str))
            count++;
    }
    cout << count;
    return 0;
}