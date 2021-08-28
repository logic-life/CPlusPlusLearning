#ifdef _LISTNODE_BYREFERENCE_HPP_
#include <iostream>

struct ListNode
{
    int value;
    ListNode *next;
    ListNode() : value(0), next(nullptr) {}
    ListNode(int x) : value(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : value(x), next(next) {}
};

void addTotail(ListNode **p_head, int value)
{
    ListNode *new_node = new ListNode();
    new_node->next = nullptr;
    new_node->value = value;
    if (*p_head == nullptr)
        *p_head = new_node;
    else
    {
        ListNode *p_node = *p_head;
        for (; p_node->next != nullptr; p_node = p_node->next)
            ;
        p_node->next = new_node;
    }
}

void RemoveNode(ListNode **p_head, int value)
{
    if (p_head == nullptr || *p_head == nullptr)
        return;
    ListNode *p_to_be_deleted = nullptr;
    if ((*p_head)->value == value)
    {
        p_to_be_deleted = *p_head;
        *p_head = (*p_head)->next;
    }
    else
    {
        ListNode *p_node = *p_head;
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
void ListPrintf(ListNode **p_head)
{
    ListNode *p_node = *p_head;
    std::cout << "打印链表：" << std::endl;
    for (; p_node->next != nullptr; p_node = p_node->next)
        std::cout << p_node->value << " ";
    std::cout << std::endl;
}

#endif //_LISTNODE_BYREFERENCE_HPP_