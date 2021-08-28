#include <cassert>
#include <iostream>

int getNameSize(char *name)
{
    //在函数开始除检验传入参数的合法性
    assert(name != nullptr);
    std::cout << *name << std::endl;                //此时输出为指向字符串的拷贝的首地址对应的字符
    std::cout << name << sizeof(name) << std::endl; //
    return sizeof(*name);
}
