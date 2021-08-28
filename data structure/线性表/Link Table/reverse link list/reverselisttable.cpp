#include <iostream>
#include <stack>
#include "listnode_byreference.hpp"
using namespace std;

void PrintListReversingly_Recursively(ListNode *p_head);
void PrintListReversingly_Iteratively(ListNode *p_head);
void printf(ListNode *p_head);
int main(int argc, char *argv[])
{
    ListNode *p_head = nullptr;
    // addTotail(p_head, 9);
    // addTotail(p_head, 8);
    // addTotail(p_head, 7);
    // addTotail(p_head, 6);
    // addTotail(p_head, 5);
    // addTotail(p_head, 4);
    // addTotail(p_head, 3);
    // addTotail(p_head, 2);
    // addTotail(p_head, 1);
    ListPrintf(p_head);
    PrintListReversingly_Iteratively(p_head);
    cout << endl;
    printf(p_head);
    return 0;
}

void PrintListReversingly_Iteratively(ListNode *p_head)
{
    if (p_head == nullptr)
        cout << "链表为空!" << endl;
    else
    {
        stack<ListNode *> node;
        ListNode *p_node = p_head;
        while (p_node != nullptr)
        {
            node.push(p_node);
            p_node = p_node->next;
        }
        while (!node.empty())
        {
            p_node = node.top();
            cout << p_node->value << " ";
            node.pop();
        }
    }
}
//递归本质上是一个栈结构，所以可以用递归实现栈操作
void PrintListReversingly_Recursively(ListNode *p_head)
{
    if (p_head != nullptr)
    {
        if (p_head->next != nullptr)
        {
            PrintListReversingly_Recursively(p_head->next);
        }
    }
    cout << p_head->value << " ";
}
void printf(ListNode *p_head)
{
    if (p_head == nullptr)
        cout << "链表为空 !" << endl;
    else
        PrintListReversingly_Recursively(p_head);
}