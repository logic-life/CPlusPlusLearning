#include "cmystring.h"

int main(int argc, char *argv[])
{
    char a_character_array[] = "string";
    CMystring the_first_string(a_character_array);  //调用构造函数
    CMystring the_second_string = the_first_string; //拷贝构造函数
    CMystring the_third_string;                     //默认构造函数
    CMystring the_forth_string;                     //默认构造函数
    // 使用一个实例初始化另一个实例
    CMystring the_fifth_string(the_second_string); //拷贝构造函数
    //自我赋值
    the_second_string = the_second_string;
    //连续赋值
    the_forth_string = the_third_string = the_second_string; //赋值构造运算符
    the_first_string.printf();
    the_second_string.printf();
    the_third_string.printf();
    //连续赋值
    return 0;
    //离开主函数区域，调用析构函数
}