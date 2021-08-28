#include <iostream>

using namespace std;

class MyCopyConstruct
{
private:
    int value;

public:
    explicit MyCopyConstruct(int initialization_value) : value(initialization_value)
    { //构造函数初始化列表

    } //禁止隐式转换，但是还是可以通过显示转换
    //error: invalid constructor; you probably meant ‘MyCopyConstruct (const MyCopyConstruct&)
    // MyCopyConstruct(MyCopyConstruct initialization_object){
    //     value=initialization_object.value;
    // }
    explicit operator bool() { return true; }//不允许使用复制列表初始化和复制初始化

    MyCopyConstruct(const MyCopyConstruct &initialization_object)
    {
        value = initialization_object.value;
        cout << "拷贝构造函数" << endl;

        
    }
    void PrintValue()
    {
        cout << "value:" << value << endl;
    }
};