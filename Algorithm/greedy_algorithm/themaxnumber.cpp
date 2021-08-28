#include <iostream>

using namespace std;

static int count[10];

void getInput()
{
    int i;
    printf("请输入测试数据：\n");
    while (scanf("%d", &i) != EOF)
        count[i]++;
}

long int minimizeNumber(int c[])
{
    long int the_minimize_number=0;
    for (int i = 1; i < 10; i++)
        if (c[i] > 0)
        {
            the_minimize_number = i;
            --c[i];
            break;
        }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < c[i];j++)
            the_minimize_number = the_minimize_number * 10 + i;
    }
    return the_minimize_number;
}
int main(void)
{
    getInput();
    cout<<minimizeNumber(count);
    return 0;
}