# 断言（assert）
**是C语言中常用的防御式编程方式，减少编程错误。最常用的是函数开始的地方，检测所有参数。有时候也可以在调用函数后，检测上下文是否正确。**
**使用钱需要添加标准库assert**
```
#include <cassert>//或者assert.h
```
> 代码案例：[assert_test.cpp](./assert_test.cpp)

当程序以release配置编译时（定义了NDEBUG宏），assert()不会做检测；
而当在debug配置时（没定义NODEBUG宏）,则会在运行时检测assert(cond)中的条件是否为真（非0），断言失败会直接令程序直接崩溃。
```
#define NDEBUG
#include <iostream>
#include <assert.h>

using namespace std;

int main()
{

    int x = 5;
    //经过运行后，值变为9
    x = 9;
    //编译器认为还是预先设定的值
    assert(x == 5);
    return 0;
}

```

> 代码案例：[ignore_assert.cpp](./ignore_assert.cpp)
