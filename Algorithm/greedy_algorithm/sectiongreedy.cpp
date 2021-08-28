#include <iostream>
#include <algorithm>
#define MAX_SEC 110
using namespace std;

struct Section
{
    double x;
    double y;
} sec[MAX_SEC];

bool cmp(const Section &a, const Section &b)
{
    if (a.x != b.x)
        return a.x > b.x;//将区间按照左区间的从大到小排列
    else
        return a.y < b.y;//对于左区间相同的，采取右区间从小到大排列
}
int main(void)
{
    int n;
    while (scanf("%d", &n), n != 0)
    {
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &sec[i].x, &sec[i].y);
//策略每次保证剩余的空间最大，所以每次选取最大的左区间作为当前节点
        sort(sec, sec + n, cmp);
        int ans = 1, last_x = sec[0].x;
        for (int i = 1; i < n; i++)
        {
            if (sec[i].y <= last_x)
            {
                last_x = sec[i].x;
                ans++;
            }
        }
        cout << ans;
    }
    return 0;
}