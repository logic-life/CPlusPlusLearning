#include <iostream>

class Shape
{

public:
    virtual void printf();
    virtual void side() = 0;
};
void Shape::printf(){

    std::cout << "输出形状："<<std::endl;
}
