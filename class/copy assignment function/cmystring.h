#include <iostream>
#include <string.h>

class CMystring
{
private:
    /* 赋值构造运算符 */
    char *my_data;

public:
    CMystring();
    CMystring(const CMystring &str);
    //CMystring(char *data=nullptr) 为啥和默认构造函数会互相冲突
    CMystring(char *data); //函数声明允许对形参进行赋值，但是定义不允许
    CMystring &operator=(const CMystring &str);
    void printf();
    ~CMystring();
};

//拷贝构造函数
CMystring::CMystring(const CMystring &str)
{
    std::cout << "拷贝构造函数" << std::endl;
    if (this != &str)
    { //不允许释放未创建对象的内存
        //delete[] my_data;
        my_data = new char[strlen(str.my_data) + 1];
        strcpy(my_data, str.my_data);
    }
}

//规范，根据输入的参数的大小申请变量内存大小
CMystring::CMystring(char *data)
{ //该写法未考虑异常安全性，如果内存不够会导致 new char抛出异常，my_data将会是空指针。
    std::cout << "构造函数" << std::endl;
    if (data == nullptr)
    {
        my_data = new char[1];
        my_data[0] = '\0';
    }
    else
    {
        my_data = new char[strlen(data) + 1];
        strcpy(my_data, data);
    }
}

//默认构造函数
CMystring::CMystring(/* args */)
{
    my_data = nullptr;
    std::cout << "默认构造函数" << std::endl;
}

//赋值构造运算符
//该写法未考虑异常安全性，如果内存不够会导致 new char抛出异常，my_data将会是空指针。
// CMystring &CMystring::operator=(const CMystring &str)
// {
//     std::cout << "赋值构造运算符" << std::endl;
//     if (this != &str)
//     {
//         delete[] my_data;
//         my_data = new char[strlen(str.my_data) + 1];
//         strcpy(my_data, str.my_data);
//         return *this;
//     }
//     return *this;
// }
CMystring &CMystring::operator=(const CMystring &str)
{
    std::cout << "赋值构造运算符" << std::endl;
    if (this != &str) //注意自我赋值
    {
        CMystring str_temp(str);         //创建一个临时实例
        char *p_temp = str_temp.my_data; //将临时实例的数据存入p_temp;
        str_temp.my_data = my_data;      //将以前str_temp.mydata指向my_data的内存
        my_data = p_temp;                //将my_data指向临时实例的内存
    }                                    //离开区域自动调用析构函数，释放内存

    return *this;
}
void CMystring::printf()
{

    std::cout << "输出：" << my_data << std::endl;
}
//析构函数
CMystring::~CMystring()
{
    delete[] my_data;
    std::cout << "析构函数" << std::endl;
}
