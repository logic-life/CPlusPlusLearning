#include "way_assert.h"

using namespace std;

int main()  
{
    char foreign_name[] = "Tomssssss";
    char *chinese_name = "zhangsan";
    cout << "输出字符指针的大小：" << sizeof(chinese_name) << endl;  //64位对应的字符指针大小为8个字节
    cout << "输出字符串地址的大小:" << sizeof(foreign_name) << endl; //
    cout << "输出姓名:" << chinese_name << "  输出姓名长度" << getNameSize(chinese_name) << endl;
    cout << "输出姓名:" << foreign_name << "  输出姓名长度" << getNameSize(foreign_name) << endl;
    return 0;
}