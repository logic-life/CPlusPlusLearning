#include <iostream>
#include <set>

using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    //第一种方法：set集合遍历查找方法
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
    //第二种方法：链表长度对齐，遍历查找方法
    ListNode *getIntersectionNode_2(ListNode *headA, ListNode *headB);
    //第三种方法：两链表全步遍历访问
    ListNode *getIntersectionNode_3(ListNode *headA, ListNode *headB);
    friend uint getLength(ListNode *head);
    friend void getTheSameLenghtOfList(ListNode *&headA, ListNode *&headB);
};

ListNode *Solution::getIntersectionNode(ListNode *headA, ListNode *headB)
{ //创建一个集合
    set<ListNode *> data_list;
    ListNode *pointer = nullptr;
    //遍历链表A
    for (auto p = headA; p != nullptr; p = p->next)
    { //将链表A中的元素存储到集合中
        data_list.insert(p);
    }
    //遍历链表B
    for (pointer = headB; pointer != nullptr; pointer = pointer->next)
    {
        if (data_list.find(pointer) != data_list.end())
            break;
    }
    return pointer;
}
//获取链表长度
uint getLength(ListNode *head)
{
    ListNode *pointer = head;
    uint length = 0;
    for (; pointer != nullptr; pointer = pointer->next)
    {
        ++length;
    }
    return length;
}
//将两个链表置于同一长度
void getTheSameLenghtOfList(ListNode *&headA, ListNode *&headB)
{
    uint length_of_heada = getLength(headA);
    uint length_of_headb = getLength(headB);
    //如果链表1的长度大于链表2，就将链表1的头向前移动length_of_heada-length_of_headb的位置
    if (length_of_heada >= length_of_headb)
    {
        for (int i = 0; i < length_of_heada - length_of_headb; i++)
        {
            headA = headA->next;
        }
    }
    else
    { //反之，链表2的头向前移动length_of_headb-length_of_heada的长度
        for (int i = 0; i < length_of_headb - length_of_heada; i++)
        {
            headB = headB->next;
        }
    }
}

ListNode *Solution::getIntersectionNode_2(ListNode *headA, ListNode *headB)
{
    ListNode *result_1 = headA;
    ListNode *result_2 = headB;
    //链表a,b如果有一个为空链表直接返回无相同节点
    if (result_1 == nullptr || result_2 == nullptr)
        return NULL;
    //反之，将两个链表放到相同长度比较
    getTheSameLenghtOfList(result_1, result_2);
    while (result_1 != result_2)
    {
        if (result_1 == nullptr || result_2 == nullptr)
            return NULL;
        result_1 = result_1->next;
        result_2 = result_2->next;
    }

    return result_1;
}

ListNode *Solution::getIntersectionNode_3(ListNode *headA, ListNode *headB)
{
    ListNode *pointer = headA;
    ListNode *position = headB;
    while (pointer!=position)
    {
        pointer = pointer == NULL ? headB:pointer->next;
        position = position == NULL ? headA : position->next;
    }
    return pointer;
}