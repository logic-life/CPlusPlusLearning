#ifdef _LISTNODE_BYPOINTER_HPP_
#include <iostream>
#include <cmath>
struct ListNode
{
    int value;
    ListNode *next;
    ListNode() : value(0), next(nullptr) {}
    ListNode(int x) : value(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : value(x), next(next) {}
};
//添加节点
void addTotail(ListNode *&p_head, int value)
{ //申请一个节点内存
    ListNode *new_node = new ListNode(value);
    new_node->next = nullptr;
    //如果没有头结点就创建一个
    if (p_head == nullptr)
        p_head = new_node;
    else
    { //在头结点后添加节点
        ListNode *p_node = p_head;
        for (; p_node->next != nullptr; p_node = p_node->next)
            ;
        p_node->next = new_node;
    }
}
//删除节点
void RemoveNode(ListNode *&p_head, int value)
{ //头结点为空，无需删除
    if (p_head == nullptr)
        return;
    //将待释放指针置为空
    ListNode *p_to_be_deleted = nullptr;
    //判断头结点是否为要删除的节点
    if (p_head->value == value)
    {
        p_to_be_deleted = p_head;
        p_head = p_head->next;
    }
    else
    { //遍历寻找待删除的节点
        ListNode *p_node = p_head;
        while (p_node->next != nullptr && p_node->next->value != value)
        {
            p_node = p_node->next;
        }
        if (p_node->next != nullptr && p_node->next->value == value)
        {
            p_to_be_deleted = p_node->next;
            p_node->next = p_node->next->next;
        }
    }
    if (p_to_be_deleted != nullptr)
    {
        delete p_to_be_deleted;
        p_to_be_deleted = nullptr;
    }
}
//打印节点
void ListPrintf(ListNode *&p_head)
{
    ListNode *p_node = p_head;
    std::cout << "打印链表：" << std::endl;
    for (; p_node != nullptr; p_node = p_node->next)
        std::cout << p_node->value << " ";
    std::cout << std::endl;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *p_head = new ListNode(-1), *node = p_head;
    int carry_data = 0;
    while (l1 != nullptr || l2 != nullptr || carry_data != 0)
    {
        if (l1 != nullptr)
        {
            carry_data += l1->value;
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            carry_data += l2->value;
            l2 = l2->next;
        }
        node->next = new ListNode(carry_data % 10);
        node = node->next;
        carry_data /= 10;
    }
    return p_head->next;
}

// 将单链表A、B合成为链表A，其中链表A、B均有序
ListNode *mergeList(ListNode *&p, ListNode *&s)
{
    // 传入链表A,B的两个头结点
    // cur为A链表当前结点的位置，p为A链表当前结点的位置，s对应B链表当前结点的位置
    ListNode *head = new ListNode(-1);
    ListNode *cur = head;

    while (p != nullptr && s != nullptr)
    {
        if (p->value <= s->value)
        {
            // 第一种情况，下个结点为链表A中的值，将当前结点指针指向A中的结点，下一个结点指针顺移即可
            //注意不能写成cur=p;p=p->next;cur指向链表B之后就不在是在A上顺移了，需要在A,B上来回切换
            cur->next = p;
            p = p->next;
        }
        else
        {
            // 第二种情况，下个结点是链表B中的值，那么将当前结点指针指向B中的结点，B中下一个结点指针顺移
            cur->next = s;
            s = s->next;
        }
        cur = cur->next;
    }
    // 当链表A、B有一方剩余结点为0时,指向非空的链表下一个结点即可
    cur->next = p != nullptr ? p : s;
    // 删除链表B的头结点
    return head->next;
}

#endif // _LISTNODE_BYPOINTER_HPP_