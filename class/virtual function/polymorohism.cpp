#include <iostream>
using namespace std;

class Shape
{
protected:
    int width, height;

public:
    Shape(int a = 0, int b = 0)
    {
        width = a;
        height = b;
    }
    // 此时调用时不会根据变量的类型来调用而是根据对象的指针内容
    virtual int area() = 0;

    // virtual int area()
    // {
    //     cout << "shape class area :" << endl;
    // }
};
class Rectangle : public Shape
{
public:
    Rectangle(int a = 0, int b = 0) : Shape(a, b) {}
    int area()
    {
        cout << "Rectangle class area :" << endl;
        return (width * height);
    }
};
class Triangle : public Shape
{
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) {}
    int area()
    {
        cout << "Triangle class area :" << endl;
        return (width * height / 2);
    }
};
// 程序的主函数
int main()
{
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);

    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 area
    shape->area();

    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 area
    shape->area();

    return 0;
}