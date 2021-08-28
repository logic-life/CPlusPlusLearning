#include <iostream>
#include "string.h"
#include <stdlib.h>
using namespace std;

class Kmp
{
private:
    int **dp;
    string pat;
    void kmpConstruct(string pat);

public:
    Kmp(string pat);
    ~Kmp();
    int searchString(string txt);
};

Kmp::Kmp(string str) : pat(str)
{
    this->dp = new int *[pat.size()]();
    for (int i = 0; i < pat.size(); i++)
        dp[i] = new int[128]();
    kmpConstruct(pat);
}

Kmp::~Kmp()
{
    for (int i = 0; i < pat.size(); i++)
        delete[] dp[i];
    delete[] dp;
}
// dp数组创建
void Kmp::kmpConstruct(string pat)
{
    // 确定状态转移的行为，必须明确：
    // 当前的匹配状态，另一个是遇到的字符
    int pattern_length = pat.size();
    // 只有当匹配到pat[0]时才能从状态0转为状态1
    dp[0][pat[0] - ' '] = 1;
    int x = 0;
    for (int j = 1; j < pattern_length; j++)
    {
        for (int c = 0; c < 128; c++)
            if (c == pat[j] - ' ')
                // 状态推进
                dp[j][c] = j + 1;
            else
                // 状态重启
                // 委托x计算重启位置
                dp[j][c] = dp[x][c];
        // 更新状态
        x = dp[x][pat[j] - ' '];
    }
}

// 文本匹配
int Kmp::searchString(string txt)
{
    int pattern_length = pat.size();
    int txt_length = txt.size();
    int j = 0;
    for (int i = 0; i < txt_length; i++)
    {
        // 当前为状态j，遇到字符txt[i]
        // 对应pat应该转移到哪个状态？
        j = dp[j][txt[i] - ' '];
        if (j == pattern_length)
            return i - pattern_length + 1;
    }
    return -1;
}

int strStr(string haystack, string needle)
{
    int haystack_size = haystack.size();
    int needle_size = needle.size();
    int **dp = new int *[needle_size];
    for (int i = 0; i < needle_size; i++)
        dp[i] = new int[26]();
    dp[0][needle[0] - 'a'] = 1;
    int x = 0;
    for (int i = 1; i < needle_size; i++)
    {
        for (int c = 0; c < 26; c++)
        {
            if (c == needle[i] - 'a')
                dp[i][c] = i + 1;
            else
                dp[i][c] = dp[x][c];
        }
        x = dp[x][needle[i] - 'a'];
    }
    int i = 0;
    for (int j = 0; j < haystack_size; j++)
    {
        i = dp[i][haystack[j] - 'a'];
        if (i == needle_size)
            return j - needle_size + 1;
    }
    return -1;
}
int main(int argc, char *argv[])
{
    // Kmp str("ababc");
    // string text = "abdabababc";
    // cout << str.searchString(text);
    string str1 = "abdabababc";
    string str2 = "ababc";
    cout << strStr(str1, str2);
    return 0;
}