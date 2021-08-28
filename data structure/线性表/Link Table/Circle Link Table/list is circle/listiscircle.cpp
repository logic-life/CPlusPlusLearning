#include <iostream>
#include "listnode_byreference.hpp"

bool hasCycle(ListNode *head);

int main(int argc, char *argv[])
{
    ListNode *p_head = new ListNode(4, nullptr);
    ListNode node1(4);
    ListNode node2(5);
    ListNode node3(6);
    ListNode node4(7);
    p_head->next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node1;
    std::cout << hasCycle(p_head) << std::endl;
    return 0;
}
