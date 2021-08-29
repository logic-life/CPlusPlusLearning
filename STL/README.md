# STL

**C++ 标准中，stl被重新组织为 13 个头文件**

| `<iterator>` | `<functional>` | `<vector>`  | `<deque>`  |
| :------------: | ---------------- | ------------- | ------------ |
|   `<list>`   | `<queue>`      | `<stack>`   | `<set>`    |
|   `<map>`   | `<algorithm>`  | `<numeric>` | `<memory>` |
| `<utility>` |                  |               |              |

## Vector

### vector使用时注意事项

### 1. 在不确定的情况下使用at而不是operator[]

在前面访问元素小节那里我们说了，at会检查是否越界，假设不确定当前访问动作是否会越界，那么我们应该使用at函数。

### 2. 什么类型不可以作为vector的模板类型

对于vector模板特化类型，因为在vector的实现过程中，变量会经常被拷贝或者赋值，所以vector的模板类型应该具有公有的拷贝构造函数和重载的赋值操作符函数。

### 3. 什么情况下vector的迭代器会失效

* 第一是在vector容器中间根据指定迭代器删除元素，也就是调用erase函数，此时因为当前位置会被后面的元素覆盖，所以该指定迭代器会失效，不过此时可以通过erase的返回值重新得到当前位置的正确迭代器；
* 第二是在vector需重新申请内存的时候，比如扩容，比如释放未使用的内存等等这些过程中都会发生迭代器失效的问题，因为内存有了变动，此时就需要重新获得迭代器；

有人说往vector中间插入数据也会使迭代器失效，实际上根据源码是不会的，看上面的insert实现可以得知，再插入完成以后给当前迭代器重新赋值了的。

### 4. vector怎么迅速的释放内存

有人说是不是可以调用reserve(0)来进行释放，毕竟reserve函数会根据我们指定的大小重新申请的内存，那是行不通的哈，这个函数只有在传入大小比原有内存大时才会有动作，否则不进行任何动作。

至于通过resize或者clear等都是行不通的，这些函数都只会对当前已保存在容器中的所有元素进行析构，但对容器本身所在的内存空间是不会进行释放的。

#### 4.1 通过swap函数

这时我们可以想想，什么情况下vector大小为0呢，就是作为一个空容器的时候，所以要想快速的释放内存，我们可以参考swap函数机制，用一个空的vector与当前vector进行交换，使用形如 `vector<int>().swap(v)`这样的代码，将v这个vector变量所代表的内存空间与一个空vector进行交换，这样v的内存空间等于被释放掉了，而这个空vector因为是一个临时变量，它在这行代码结束以后，会自动调用vector的析构函数释放动态内存空间，这样，一个vector的动态内存就被迅速的释放掉了。

#### 4.2 使用shrink_to_fit函数

在c++11以后增加了这个函数，它的作用是释放掉未使用的内存，假设我们先调用clear函数把所有元素清掉，这样是不是整块容器都变成未使用了，然后再调用shrink_to_fit函数把未使用的部分内存释放掉，那不就把这个vector内存释放掉了吗。

参考：

1. [VECTOR详解](https://zhuanlan.zhihu.com/p/377186496)
2. [vector库函数](http://www.cplusplus.com/reference/vector/vector/)
3. [Vector库函数](https://zh.cppreference.com/w/cpp/container/vector)

## Set

**set翻译为集合，是一个内部自动有序且不包含重复元素的容器！使用set前需要添加头文件#include `<set>`,除此之外需要添加using namespace std;**

set底层是使用红黑树实现的！

注意点：如果使用自定义类型实现set，那么必须重写operator<（）函数，因为内部调用时候需要排序。

参考：

1. [set详解](https://www.nhooo.com/cpp/cpp-set.html)
2. [set](https://zh.cppreference.com/w/cpp/container/set)
