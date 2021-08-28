#include <iostream>
void getSeconds(unsigned long *pair);
int main()
{
    //无法使用空地址的指针变量由函数进行改变，空地址的指针指向内存空间不存在
    unsigned long time_now;
    getSeconds(&time_now);
    std::cout << "输出当前时间：" << time_now << std::endl;
    return 0;
}
void getSeconds(unsigned long *pair)
{
    *pair = time(NULL);
}