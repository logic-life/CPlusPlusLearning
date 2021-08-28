#define _LISTNODE_BYPOINTER_HPP_ //执行bypointer文件
#include "listnode_byreference.hpp"
#include <cmath>
class solution
{
private:
    /* data */
public:
    solution(/* args */);
    ~solution();
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
};

solution::solution(/* args */)
{
}

solution::~solution()
{
}

ListNode *solution::addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *node = new ListNode();
    //设置位置指针
    ListNode *pointer = nullptr;
    ListNode *p = nullptr;
    //分别统计各个链表的长度
    int length_of_l1 = 0;
    int length_of_l2 = 0;
    //进位存储
    int plus_number = 0;
    for (pointer = l1; pointer != nullptr; pointer = pointer->next)
        ++length_of_l1;
    for (pointer = l2; pointer != nullptr; pointer = pointer->next)
        ++length_of_l2;
    //将两个位置指针指向链表头
    pointer = l1;
    p = l2;
    //链表1长度大于链表2
    if (length_of_l1 >= length_of_l2)
    {
        //遍历两表相同部分，相加取余
        for (int i = 0; i < length_of_l2; i++)
        {
            pointer->value = (plus_number + pointer->value + p->value) % 10;
            plus_number = floor((plus_number + pointer->value + p->value) / 10);
            pointer = pointer->next;
            p = p->next;
        }
        for (int i = length_of_l1; i < length_of_l2; i++)
        {
            pointer->value = (pointer->value + plus_number) % 10;
            plus_number = floor((pointer->value + plus_number) / 10);
            pointer = pointer->next;
        }
        //边界条件
        if (plus_number > 0 && pointer == nullptr)
        {
            node->value = plus_number;
            pointer = node;
        }
        return l1;
    }
    else //链表2的长度大于链表1
    {
        for (int i = 0; i < length_of_l1; i++)
        {
            p->value = (plus_number + pointer->value + p->value) % 10;
            plus_number = floor((plus_number + pointer->value + p->value) / 10);
            pointer = pointer->next;
            p = p->next;
        }
        for (int i = length_of_l1; i < length_of_l2; i++)
        {
            p->value = (p->value + plus_number) % 10;
            plus_number = floor((p->value + plus_number) / 10);
            p = p->next;
        }
        //边界条件
        if (plus_number > 0 && p->next == nullptr)
        {
            node->value = plus_number;
            p = node;
        }
        return l2;
    }
}