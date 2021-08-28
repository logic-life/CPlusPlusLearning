#include <iostream>
#include <queue>
#include <stack>

using namespace std;
bool isPalindrome(int x)
{
    int i = 1;
    vector<int> v;
    int t;
    while (x)
    {
        t = x % 10;
        v.push_back(t);
        x /= 10;
    }
    for (auto i = v.begin(), j = v.end() - 1; i < j; i++, j--)
        if (*i != *j)
            return false;
    return true;
}

int main(void)
{
    int x = 102;
    cout << isPalindrome(x);
    return 0;
}