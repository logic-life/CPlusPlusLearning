#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    //定义输入的字符串
    string s;
    vector<string> str;

    while (getline(cin, s, ' '))
        str.push_back(s);
    for (auto i = str.rbegin(); i != str.rend(); i++)
        cout << *i << " ";

    return 0;
}