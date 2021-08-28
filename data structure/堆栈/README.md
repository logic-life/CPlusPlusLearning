# 栈

## 基本知识

**栈是一种先进后出的数据结构，可以把栈理解为手枪弹夹，每次只可以将最上方的子弹弹出或者将最上方的子弹放入。**

关于栈的四个问题：

+ c++？中stack是容器吗
+ 我们使用的stack是属于哪个版本的STL?
+ STL中的stack是如何实现的？
+ stack提供迭代器来访问stack空间吗？

目前存在三个最为普遍的的STL版本：

+ HP STL：其他版本的STL一般是以HP STL为蓝本实现的，HP STL是c++STL的第一个实现版本，并且开放源码；
+ P.J.Plauger STL：由P.J.Plauger参照HP STL实现出来的，被Visual C++编译器所采用，不是开源的；
+ SGI STL：由Silicon Graphics Computer Systems公司参照HP STL实现，被Linux的C++编译器GCC所采用，SGI STL是开源软件，源码可读性甚高。

栈提供push和pop等等接口，所有元素必须符合先进后出规则，所以栈不提供走访功能，也不提供迭代器（iterator),不像set和map提供迭代器(iterator)来遍历元素。

栈是以底层容器完成其所有的工作，对外提供统一的接口，底层容器是可以插拔的（我们可以控制使用哪种容器来实现栈的功能），STL中栈往往不被归类为容器，而是容器适配器（container adaptor)。

deque是一个双向队列，只要封住一段，只开通另一端就可以实现栈的逻辑。

SGI STL中队列底层实现缺省条件下也是使用deque实现的。

我们也可以指定vector为栈的底层实现，初始化语句如下：

```
std::stack<int, std::vector<int> > third;  // 使用vector为底层容器的栈
```

刚刚讲过栈的特性，对应的队列的情况是一样的。

队列中先进先出的数据结构，同样不允许有遍历行为，不提供迭代器, **SGI STL中队列一样是以deque为缺省情况下的底部结构。**

也可以指定list 为起底层实现，初始化queue的语句如下：

```
std::queue<int, std::list<int>> third; // 定义以list为底层容器的队列
```

所以STL 队列也不被归类为容器，而被归类为container adapter（ 容器适配器）。

## 存储结构

[顺序栈](.\stack\sequential_stack.h)：栈的顺序存储结构称之为顺序栈。由于栈是运算受限的线性表，因此线性表的存储结构也对栈有效。

顺序栈的定义如下：

```
struct SeqStack
{
    /* 顺序栈的结构 */
    // 顺序栈元素存储位置
    DataType data[stack_size];
    int top;
};
```

[链栈](.\stack\link_stack\link_stack.h)：为了克服顺序存储分配带来的固定分配空间所产生的溢出和空间浪费问题，可以采用链式存储结构来存储栈，栈的链式存储称之为链栈。

链栈的定义如下：

```
typedef char DataType;
struct ListNode
{
    DataType data;
    ListNode *next;
    ListNode(DataType d, ListNode *n) : data(d), next(n){};
    ListNode(DataType d) : data(d){};
};

```

## 应用

+ 进制转换
+ 栈与递归

# 队列

队列也是一种操作受限的线性表，它只允许在表的一端进行元素的插入（入队），而在另一头进行元素的删除（出队）。

允许插入的一端称之为队尾（rear）,允许删除的一端称之为对头（front）；**特点：FIFO。**

## 基本运算

+ 初始化initQueue(q)
+ 判断队列是否为空queueEmpty(q)
+ 入队列enQueue(q),队列不满，插入队尾
+ 出队列DeQueue(q)，队列不空，返回队头，并删除队头
+ 取队头getFront(q)，队列不空，返回队头元素。

## 存储结构

顺序队列:队列的顺序存储结构称之为顺序队列；由于队列的队头和队尾的位置是变化的，因此需要设置两个指针front和rear分别指示队头元素和队尾元素在表中的位置。它们的初值在队列初始化的位置为0.

```
#define QUEUESIZE 100
typedef struct
{
	DataType data[QUEUESIZE];
	int front,rear;
}
```

前缀表达式：运算符放在两个操作数之前。

中缀表达式：运算符放在两个操作数的中间。

后缀表达式：运算符紧紧跟在两个操作数之后
