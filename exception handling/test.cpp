#include <iostream>

using namespace std;

double division(int left, int right)
{
    // 根据throw后面跟随的表达式类型决定抛出的异常类型。
    if (right == 0)
        throw 1;
    if (right == 1)
        throw "Division by zero condition !";
    return left / right;
}

int main(int argc, char *argv[])
{
    int a, b;
    double z;
    cin >> a >> b;
    try
    {
        z = division(a, b);
        cout << z << endl;
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
    catch (int m)
    {
        cerr << m << endl;
    }
    return 0;
}