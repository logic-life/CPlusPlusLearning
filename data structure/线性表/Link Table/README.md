# 链表

链式存储是一种最常用的存储方式之一，不仅可以表示线性表，还可以用来表示各种非线性的数据结构：树，队列，图。

## 单链表

### 存储结构

使用链式存储结构表示每个元素数据元素时，除了存储本身的信息外，还需要一个存储指示其后继元素存储位置的指针，由这两部分构成元素的存储映像—结点。

```
struct ListNode
{
    int value;
    ListNode *next;
    ListNode():value(0),next(nullptr){}
    ListNode(int x):value(x),next(nullptr){}
    ListNode(int x,ListNode *next) : value(x), next(next) {}
};
```

### 单链表的两种创建方式

+ 头插法
+ 尾插法

### [单链表的模板类定义](./单链表/单链表的模板类/template_single_link_list.h)

> **使用模板类需要注意template `<class T>`必须声明和定义在同一个文件，否则会无法识别。**
> 只有当实例化一个模板时，编译器才能看到模板确切的定义，而不仅仅是它的定义。模板定义很特殊，由它处理的任何东西都意味着编译器在当时不为其分配存储空间（没有具体的函数不会对模板实例化），会一直处于等待模板实例被告知的状态，**为了容易使用，几乎总是在头文件中放置全部的模板的声明和定义**。
>
> ```
> 由于c++是独立编译，先将cpp文件独立编译成三个独立的目标文件(.obj)然后再通过链接器链接起来，生成可执行文件。如果当前文件找不到函数定义(一般写法，函数声明和定义分离)，则会在函数位置生成符号，在链接时，再寻找这个函数。而模板类是两次编译，第一次编译只会对模板进行编译，不生成具体函数，而在调用时才生成具体函数。因为编译器无法知道实参具体是什么类型。因此模板的实例化与定义体必须放到同一翻译单元中。
> ```

## [循环链表](./循环链表/链表判环/listnode_byreference.hpp)

> 循环链表是链式存储结构的另一种形式，特点是单链表的最后一个结点的指针域不为空，而是指向链表的头结点，使链表构成一个环。因此从结点的任何一个结点都可以访问表中的其他结点，这种结构形式的链表为单循环链表。
>
> **循环链表的结构类型和单链表完全相同，在操作上也一致，差别是在于算法中循环的结束条件为是否等于头指针。**



## [静态链表](./链表/静态链表/chaintable_learning.cpp)

[双向链表](./链表/双向链表/chaintable.h)

**函数形参为什么要使用指向指针的指针，或者指针引用？**

```apache
//如果函数体形参调用是值传递，那么对应头节点的指针传递进去，被复制一份copy后，此后所有的修改都是在copy中进行的，
与原指针无关，并不会对传入的头结点的指针进行修改。而指针引用和指向指针的指针才会更改head节点指向的内容！

void addTotail(ListNode *&p_head, int value)
{ 
    ListNode *new_node = new ListNode();
    new_node->next = nullptr;
    new_node->value = value;
    if (p_head == nullptr)
        p_head = new_node;
    else
    {
        ListNode *p_node = p_head;
        for (; p_node->next != nullptr; p_node = p_node->next)
            ;
        p_node->next = new_node;
    }
}

```

---

[头结点的指向指针的指针创建](./listnode_bypoint.hpp)

---

[头结点的指针引用的创建](./listnode_byreference.hpp)
