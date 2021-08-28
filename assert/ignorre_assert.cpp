#define NDEBUG
#include <iostream>
#include <assert.h>

using namespace std;

int main()
{

    int x = 5;
    //经过运行后，值变为9
    x = 9;
    //编译器认为还是预先设定的值
    assert(x == 5);
    return 0;
}
