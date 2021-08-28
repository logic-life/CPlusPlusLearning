#include <iostream>
// 创建一个最大元素数量为100的栈
#define stack_size 100
// 顺序栈
typedef char DataType;
struct SeqStack
{
    /* 顺序栈的结构 */
    // 顺序栈元素存储位置
    DataType data[stack_size];
    int top;
};

// 置空栈初始化
void initStack(SeqStack *s)
{
    // 由于c语言下标从0开始，因此将空栈即为0
    s->top = -1;
}

// 判断栈是否为空
bool stackEmpty(SeqStack *s)
{
    return s->top == -1;
}

// 判断栈是否满栈
bool stackFull(SeqStack *s)
{
    return s->top == stack_size - 1;
}

// 进栈
void push(SeqStack *s, DataType x)
{
    if (stackFull(s))
    {
        printf("stack overflow");
        exit(1);
    }
    s->top++;
    s->data[s->top] = x;
}

DataType pop(SeqStack *s)
{
    if (stackEmpty(s))
    {
        printf("stack undeflow");
        exit(-1);
    }
    return s->data[s->top--];
}

DataType getTop(SeqStack *s)
{
    if (stackEmpty(s))
    {
        printf("stack empty");
        exit(0);
    }
    return s->data[s->top];
}