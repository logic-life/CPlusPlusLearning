#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    //getline函数使用方法
    string str;
    //定义单词长度
    int count = 0;
    //getline(cin, str, '\n');
    getline(cin, str);
    for (auto i = str.end() - 1; *i != ' '; i--)
    {
        count++;
        if (i == str.begin())
            break;
    }
    cout << count;
    
    return 0;
}