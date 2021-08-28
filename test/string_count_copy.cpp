#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct CH
{
    char c;
    int n;
};

bool cmp(struct CH a, struct CH b)
{
    if (a.n != b.n)
        return a.n > b.n;
    else
        return a.c < b.c;
}

int CHAR[256];
vector<CH> C;
int main()
{
    string s;
    while (getline(cin, s))
    {
        for (int i = 0; i < 256; i++)
            CHAR[i] = 0;
        for (auto c : s)
        {
            CHAR[c]++;
        }
        for (int i = 0; i < 256; i++)
        {
            struct CH tmp;
            tmp.c = i;
            tmp.n = CHAR[i];
            C.push_back(tmp);
        }
        sort(C.begin(), C.end(), cmp);
        for (int i = 0; i < (int)C.size(); i++)
            if (C[i].n > 0)
                cout << C[i].c;
        cout << endl;

        C.clear();
    }
    return 0;
}