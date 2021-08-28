#include <iostream>

using namespace std;

constexpr int factorial(int n)
{
    return n > 1 ? n * factorial(n - 1) : 1;
}

int main(void)
{

    constexpr int i = 10;
    const int n = 10;
    constexpr const int *p = nullptr;
    cout << "编译" << endl;
    cout << factorial(i) << endl;
    cout << factorial(n);
    //并不会报错,调用值必须为字面值
    int array[factorial(3)];

    return 0;
}