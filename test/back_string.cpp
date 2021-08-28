#include <iostream>

using namespace std;

bool backspaceCompare(string s, string t)
{
    // 初始化指向s和t的两个指针，分别指向字符串的尾元素
    int p = s.size() - 1, q = t.size() - 1;
    // 初始化p和q跳过的元素个数
    int p_jump = 0, q_jump = 0;
    for (; p >= 0 && q >= 0; p--, q--)
    {

        if (s[p] == '#')
            p_jump++;
        else
        {
            if (p_jump > 0)
            {
                p--;
                p_jump--;
            }
        }
        if (t[q] == '#')
            q_jump++;
        else
        {
            if (q_jump > 0)
            {
                q--;
                q_jump--;
            }
        }
        if (s[p] != '#' && t[q] != '#')
        {
            if (s[p] != t[q])
                return false;
        }
    }
    return true;
}
int main(int argc, char *argv[])
{

    string s, p;
    s = "ab##";
    p = "c#d#";
    cout << backspaceCompare(s, p);

    return 0;
}