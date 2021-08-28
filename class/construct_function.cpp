#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
    Shape(int l, int w) : length(l), width(w) {}

private:
    int length;
    int width;
};

int main(int argc, char *argv[])
{
    // 由于没有定义默认构造函数，所以只能使用已经定义的构造函数显示初始化shape成员。
    // no matching function for call to 'Shape::Shape()'
    // Shape triangle;

    Shape triangle(10, 8);
    // 无法使用动态分配数组的元素类型
    // no matching function for call to 'Shape::Shape()'
    // Shape *square = new Shape[3];

    // 使用容器时也不在接受只添加对象数量，不提供初始化值的情况
    vector<Shape> new_angle(10);

    return 0;
}