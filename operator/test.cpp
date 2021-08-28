#include <iostream>

using namespace std;

int main()
{

    int a = 4;
    int b = 9;
    cout << "输出交换后的两个值" << a << b << endl;
    a = a ^ b; //存储ab异或的值
    b = a ^ b; //交换b的值
    a = a ^ b; //交换a的值
    cout << "输出交换后的两个值" << a << b << endl;

    a = 5;
    b = 5;
    int c, d;
    c = (a++) + (a++) + (a++);
    d = (++b) + (++b) + (++b);
    cout << c << " " << d;

    return 0;
}