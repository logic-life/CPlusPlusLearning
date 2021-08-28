#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string str;
map<char, int> char_count;
int main(int argc, char *argv[])
{
    AlphaTime temp;
    while (getline(cin, str))
    {
        for (auto i : str)
            ++char_count(i);

        sort(string_count.begin(), string_count.end(), [](const AlphaTime &item1, const AlphaTime &item2)
             { return item1.time > item2.time; });

        for (auto i : string_count)
            cout << i.al;
        cout << endl;
        string_count.clear();
    }

    return 0;
}