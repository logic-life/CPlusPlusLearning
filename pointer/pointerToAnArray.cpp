#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{ //二维数组行数可以不定义，但是列数必须定义
    char c[][8] = {"apple", "orange", "banana"};
    char(*pointer)[8] = &c[2];
    char a[] = {"name"};
    char *p = a;//相当于&a[0]
    //m = &c[1];
    cout << typeid(pointer).name()
         << "\n"
         << typeid(c[2]).name() << endl;
    cout << **pointer << "\n"
         << *pointer << p << endl;
}

