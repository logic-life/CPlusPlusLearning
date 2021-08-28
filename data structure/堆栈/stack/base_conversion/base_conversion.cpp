#include <iostream>
#include <stack>
using namespace std;

int baseConversion(int n, int k)
{
    // 输入十进制数，以及目标进制
    stack<int> left_stack;
    int aim_num = 0;
    while (n != 0)
    {
        left_stack.push(n % k);
        n /= k;
    }
    while (!left_stack.empty())
    {
        aim_num = aim_num * 10 + left_stack.top();
        left_stack.pop();
    }
    return aim_num;
}

int main(int argc, char *argv[])
{
    // 输入十进制数，以及目标进制
    int decimal_number, aim_base;
    cout << "请输入十进制数以及目标进制：" << endl;
    cin >> decimal_number >> aim_base;
    cout << "十进制数:" << decimal_number << "的"
         << "目标进制为：" << baseConversion(decimal_number, aim_base) << endl;

    return 0;
}