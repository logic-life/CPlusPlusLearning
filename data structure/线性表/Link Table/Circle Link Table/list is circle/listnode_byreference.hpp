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
    if (p_head == nullptr)
        std::cout << "链表为空！" << std::endl;
    else
    {
        ListNode *p_node = p_head;
        std::cout << "打印链表：" << std::endl;
        for (; p_node != nullptr; p_node = p_node->next)
            std::cout << p_node->value << " ";
        std::cout << std::endl;
    }
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

bool hasCycle(ListNode *head) // 链表判断环

{ //初始化两个快慢指针
    ListNode *fast = head;
    ListNode *slow = head;
    //不使用慢指针，会造成判断条件重复
    while (fast != nullptr && fast->next != nullptr)
    { //慢指针前进一步，快指针前进两步
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            //快指针追上慢指针，有环
            return true;
    }
    //退出循环表明无环
    return false;
}
// 带头结点的操作方便，不然判断起始处插入时麻烦,需要额外判断头结点处插入
// 循环链表插入操作,已知一个排好序的带头结点的循环链表，在循环链表中插入一个元素
void insertList(ListNode *head, int x)
{
    ListNode *new_node = new ListNode(x);
    ListNode *p = head;
    // 首先判断待插入的元素与头结点的大小
    if (x > head->value)
    {
        // 将新生成的结点作为头结点
        new_node->next = head;
        while (p->next != head)
            p = p->next;
        p->next = new_node;
        head = new_node;
    }
    // 快指针指向第一个结点，慢指针指向头结点
    ListNode *fast_node = head->next, *slow_node = head;
    // 判断头结点是否

    while (fast_node->value > x && fast_node != head)
    {
        slow_node = fast_node;
        fast_node = fast_node->next;
    }
    slow_node->next = new_node;
    new_node->next = fast_node;

    /*
    // 自己添加一个虚拟头结点解决这个问题，无需判断插入的位置，因为始终在虚拟头结点之后
    ListNode *new_node = new ListNode(x);
    ListNode *dummy_head=new ListNode(-1);
    dummy_head->next=head;
    ListNode *fast_node = dummy_head->next, *slow_node = dummy_head;
    while (fast_node->value > x && fast_node != head)
    {
        slow_node = fast_node;
        fast_node = fast_node->next;
    }
        slow_node->next = new_node;
        new_node->next = fast_node;
    */
}