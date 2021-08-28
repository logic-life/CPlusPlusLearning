#include <iostream>
// 链栈的存储结构
typedef char DataType;
struct ListNode
{
    DataType data;
    ListNode *next;
    ListNode(DataType d, ListNode *n) : data(d), next(n){};
    ListNode(DataType d) : data(d){};
};
typedef ListNode *ListStack;

// 空栈
void initStack(ListStack &top)
{
    top = nullptr;
}

// 判断是否为空栈
bool stackEmpty(ListStack top)
{
    return top == nullptr;
}

// 向栈中插入一个元素x
void pushStack(ListStack &top, DataType x)
{
    ListNode *new_node = new ListNode(x);
    new_node->next = top;
    top = new_node;
}

// 出栈
void popStack(ListStack &top)
{
    if (stackEmpty(top))
    {
        printf("stack empty");
        exit(0);
    }
    ListNode *p = top;
    top = top->next;
    delete (p);
    p = nullptr;
}

// 取栈顶元素
DataType getTop(ListStack top)
{
    if (stackEmpty(top))
    {
        printf("stack empty");
        exit(0);
    }
    return top->data;
}