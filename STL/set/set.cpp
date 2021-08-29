#include <iostream>
#include <set>
using namespace std;
struct Goods
{
    /* 商品的价格以及数量 */
private:
    double prices;
    unsigned int numbers;

public:
    //set中如果需要使用自定义类型需要重载<运算符，否则会报错
    bool operator<(const Goods &item) const
    {
        return item.prices < this->prices;
    }
    Goods() : prices(0.0), numbers(0) {}
    Goods(double p, unsigned int n) : prices(p), numbers(n) {}
    Goods(const Goods &item) : prices(item.prices), numbers(item.numbers) {}
    void show() const { cout << this->prices << this->numbers << endl; }
};

// set如何快速释放元素
void test_1()
{
    set<int> my_set = {1, 2, 3};
    // set<int> my_set;
    cout << *my_set.begin() << endl;
    // 删除set中分配的内存的方法一
    my_set.clear();
    set<int>().swap(my_set);
}

void test_2()
{
    set<int> my_set = {3, 2, 1};
    // 容器生成后，会自动根据key值进行排序
    for (auto iter = my_set.begin(); iter != my_set.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    // 释放set中的内存
    my_set.clear();
    set<int>().swap(my_set);
}

void test_3()
{
    set<Goods> surper_market = {Goods(3.4, 5), Goods(2.1, 7), Goods(6.1, 9)};
    for (set<Goods>::iterator iter = surper_market.begin(); iter != surper_market.end(); iter++)
        // 这里由于迭代器是一个常量迭代器，不允许使用迭代器改变数值，因此需要在返回的函数中末尾加入const，表示不会改变元素的值
        (*iter).show();
    cout << "输出商品的种类：" << surper_market.size() << endl;
    surper_market.clear();
    set<Goods>().swap(surper_market);
    cout << "输出商品的种类：" << surper_market.size() << endl;
}
int main(int argc, char *argv[])
{
    test_1();
    test_2();
    test_3();
    return 0;
}
