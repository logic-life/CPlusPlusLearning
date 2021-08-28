#include <iostream>

using namespace std;

void func(int a, int b)
{
    cout << "调用函数一" << endl;
}
void func(int a, int *b)
{
    cout << "调用函数二" << endl;
}

int main(int argc, char *argv[])
{

    //func(1, NULL);    //有多个重载函数
    func(1, 0);                     //调用函数1
    func(1, nullptr);               //调用函数二
    func(1, static_cast<int *>(0)); //调用函数二
    return 0;
}