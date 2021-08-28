#include "solution.h"
void Test();

int main(int argc, char *argv[])
{
    Test();
    return 0;
}

void Test()
{
    ListNode node_same1(9);
    ListNode node_same2(4);
    ListNode node_same3(5);

    ListNode *headA = new ListNode(4);
    ListNode node_a1(5);
    ListNode node_a2(6);
    ListNode node_a3(3);
    ListNode node_a4(5);
    ListNode node_a5(5);
    headA->next = &node_a1;
    node_a1.next = &node_a2;
    node_a2.next = &node_a3;
    node_a3.next = &node_a4;
    node_a4.next = &node_a5;
    node_a5.next = &node_same1;
    node_same1.next = &node_same2;
    node_same2.next = &node_same3;

    ListNode *headB = new ListNode(8);
    ListNode node_b1(5);
    ListNode node_b2(6);
    ListNode node_b3(3);
    headB->next = &node_b1;
    node_b1.next = &node_b2;
    node_b2.next = &node_b3;
    node_b3.next = &node_same1;
    Solution solve;
    cout << solve.getIntersectionNode_3(headA, headB)->val;
}