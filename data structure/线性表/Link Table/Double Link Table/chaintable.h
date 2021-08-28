#include <iostream>
#define NIL NULL
typedef struct Node
{
    int data;
    Node *next;
    Node *prev;
} Node;

class ChainTable
{
private:
    /* 哨兵 */
    Node *nil;
    int chain_table_length = 0;

public:
    ChainTable(/* args */);
    ~ChainTable();
    bool ListCreate();
    Node *ListSearch(int data) const;
    bool ListInsert(int data);
    bool ListDelete(int data);
    bool ChainTableToNull();
    int ListLength(void);

    void ShowChainTable();
};
//生成一个双向链表
ChainTable::ChainTable(/* args */)
{
    nil = nullptr;
    std::cout << "生成一个双向链表！" << std::endl;
}
//双向链表初始化
bool ChainTable::ListCreate()
{
    nil = new Node;
    //判断是否初始化成功
    if (nil == nullptr)
        return false;
    std::cout << "初始化链表成功" << std::endl;
    //哨兵初始化，next和prev均指向自身
    nil->next = nil;
    nil->prev = nil;
    nil->data = NIL;
    return true;
}
//链表查询
Node *ChainTable::ListSearch(int data) const
{ //将一个指针指向链表中的元素
    Node *pointer = nil->next;
    //遍历访问链表中的元素
    while (pointer != nil && pointer->data != data)
    {
        /* code */
        pointer = pointer->next;
    }
    return pointer; //结束后会造成内存泄露，怎么解决
}
//向链表中插入一个元素
bool ChainTable::ListInsert(int data)
{
    chain_table_length++;
    Node *node = new Node;
    if (node == nullptr)
        return false;
    node->data = data;
    node->next = nullptr;
    node->prev = nullptr;
    //node的next指向链表的下一个元素
    node->next = nil->next;
    //待插入元素的后一个元素的next指向带插入元素
    nil->next->prev = node;
    //哨兵的next指向待插入元素
    nil->next = node;
    //待插入元素的prev指向哨兵
    node->prev = nil;
    return true;
}
//删除链表中的指定元素
bool ChainTable::ListDelete(int data)
{ //判断链表是否为空
    if (chain_table_length <= 0)
    {
        std::cout << "当前链表为空，无法删除！" << std::endl;
        return true;
    }
    else
    { //链表长度减一
        chain_table_length--;
        //找到待删除元素的地址
        Node *pointer = ListSearch(data);
        if (pointer->data == NIL)
            return false;
        else
        {
            pointer->prev->next = pointer->next;
            pointer->next->prev = pointer->prev;
            return true;
        }
    }
}
//打印链表中的元素
void ChainTable::ShowChainTable()
{
    Node *pointer = nil->next;
    while (pointer != nil)
    {
        /* code */
        std::cout << "data:" << pointer->data << std::endl;
        pointer = pointer->next;
    }
}
//返回链表中元素长度
int ChainTable::ListLength(void)
{
    return chain_table_length;
}
//清空链表
bool ChainTable::ChainTableToNull()
{
    if (chain_table_length == 0)
    {
        std::cout << "当前为空表！" << std::endl;
    }
    else
    { //双指针释放内存
        Node *p = nil->next;
        Node *pointer = nullptr;
        while (p != nil)
        {
            chain_table_length--;
            pointer = p->next;
            delete p;
            p = pointer;
        }
        //恢复为空表
        nil->next = nil;
        nil->prev = nil;
    }

    return true;
}
//析构函数
ChainTable::~ChainTable()
{ //链表为空直接删除哨兵
    if (chain_table_length == 0)
    {
        delete nil;
        return;
    }
    //双指针释放内存
    Node *p = nil->next;
    Node *pointer = nullptr;
    while (p != nil)
    {
        pointer = p->next;
        delete p;
        p = pointer;
    }
    //释放哨兵内存
    delete nil;
}
