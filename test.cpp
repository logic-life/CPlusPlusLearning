#include <iostream>
#include <vector>
using namespace std;

void reverse(string::iterator first, string::iterator last)
{
    // 翻转字符串

    while ((first != last) && (first != --last))
    {
        std::iter_swap(first++, last);
    }
}
int main()
{

    string str = "hello_world";
    reverse(str.begin(), str.end());
    cout << str;
}