#ifndef _DYNAMIC_MEMORY_H_
#define _DYNAMIC_MEMORY_H_
#include <iostream>

class Shape
{

public:
    Shape()
    {
        std::cout << "这是一个构造函数" << std::endl;
    }
    ~Shape()
    {
        std::cout << "这是一个析构函数" << std::endl;
    }
};
#endif //_DYNAMIC_MEMORY_H_