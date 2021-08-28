#include <iostream>
#include <algorithm>
using namespace std;

//月饼的种类
static int n;
//市场最大需求量
static double max_capacity;

struct moonCake
{
    /* 月饼属性 */
    double store; //库存量
    double sell;  //总售价
    double price; //单价
} cake[1001];

//单价比较
bool cmp(const moonCake &a, const moonCake &b)
{
    return a.price > b.price;
}

//获取月饼的销售信息
void getInput()
{
    printf("输入月饼种类，市场最大需求量，各种类型月饼的库存以及销售金额：\n");
    scanf("%d%lf", &n, &max_capacity);
    for (int i = 0; i < n; i++)
        scanf("%lf", &cake[i].store);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell / cake[i].store;
    }
}

//求取最佳销售方案对应的最佳售价
double greedy()
{
    sort(cake, cake + n - 1, cmp);
    double profit = 0;
    for (int i = 0; i < n; i++)
        if (cake[i].store <= max_capacity)
        {
            max_capacity -= cake[i].store;
            profit += cake[i].sell;
        }
        else
        {
            profit += cake[i].price * max_capacity;
            break;
        }
    return profit;
}

int main(void)
{
    getInput();
    cout<<greedy();
    return 0;
}