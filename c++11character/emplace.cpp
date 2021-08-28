#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Foo
{
private:
    int val;
    string str;

public:
    Foo() : val(0), str("")
    {
        cout << "默认构造函数" << endl;
    }
    Foo(int v, string s) : val(v), str(s)
    {
        cout << "两个参数的构造函数" << endl;
    }

    Foo(const Foo &rhs)
    {
        val = rhs.val;
        str = rhs.str;
        cout << "拷贝构造函数" << endl;
    }

    Foo &operator=(const Foo &rhs)
    {
        val = rhs.val;
        str = rhs.str;
        cout << "赋值操作符重载" << endl;
        return *this;
    }

    ~Foo()
    {
        cout << "析构函数" << endl;
    }
};

int main(int argc, char *argv[])
{
    vector<Foo> ve;
    ve.reserve(10);
    //会生成一个临时对象，然后调用拷贝构造函数，添加对象
    cout << ve.size();
    cout << ve.capacity() << endl;
    ve.push_back(Foo(19, "jay"));
    cout << ve.size();
    cout << ve.capacity() << endl;
    //直接调用构造函数初始化，添加对象
    ve.emplace_back(18, "say");
    cout << ve.size();
    cout << ve.capacity() << endl;
    ve.insert(ve.begin(), Foo(19, "jay"));
    cout << ve.size();
    cout << ve.capacity() << endl;
    ve.push_back(Foo(19, "22"));
    return 0;
}