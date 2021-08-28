#include <iostream>

using namespace std;

int strStr(string haystack, string needle)
{
    int haystack_size = haystack.size();
    int needle_size = needle.size();
    if (haystack_size == 0 && needle_size != 0)
        return -1;
    if (haystack_size == 0 && needle_size == 0)
        return 0;
    for (int i = 0; i <= haystack_size - needle_size; i++)
    {
        int j;
        for (j = 0; j < needle_size; j++)
        {
            if (needle[j] != haystack[i + j])
                break;
        }
        if (j == needle_size)
            return i;
    }
    return -1;
}
int main(int argc, char *argv[])
{

    string str1 = "abcde";
    string str2 = "cde";
    cout << strStr(str1, str2);
}