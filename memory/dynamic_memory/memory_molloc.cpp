#include <iostream>

int main(int argc, char *argv[])
{
    double *p_value = nullptr; //  初始化为nullptr的指针
    //p_value = new double;      //申请double大小（8个字节）内存
    char *p_array = nullptr;

    if (!(p_value = new double)) //检测自由存储区内存是否用完
    {
        std::cout << "error:out of memory" << std::endl;
        exit(1);
    }
    if (!(p_array = new char[20])) //检测自由存储区内存是否用完
    {
        std::cout << "error:out of memory" << std::endl;
        exit(1);
    }
    std::cout << "申请的变量内存地址：" << p_value << std::endl;
    std::cout << "申请的变量内存大小：" << sizeof(p_value) << std::endl;
    std::cout << "申请的数组内存地址：" << &p_array << std::endl; //cout<<p_array<<endl;直接输出数组首地址，cout重载了对数组首地址输出首地址内容
    std::cout << "申请的数组内存大小：" << sizeof(p_array) << std::endl;
    delete p_value;
    delete[] p_array;
    return 0;
}