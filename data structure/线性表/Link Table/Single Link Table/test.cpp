#define _LISTNODE_BYPOINTER_HPP_ //执行bypointer文件
#include "listnode_byreference.hpp"
#include "listnode_bypoint.hpp"
void TestByReference();
//void TestByPointer();
int main(int argc, char *argv[])
{
}
void TestByReference()
{
    ListNode *p_head = nullptr;
    addTotail(p_head, 3);
    addTotail(p_head, 4);
    addTotail(p_head, 5);
    addTotail(p_head, 6);
    addTotail(p_head, 7);
    addTotail(p_head, 8);
    addTotail(p_head, 9);
    ListPrintf(p_head);
    RemoveNode(p_head, 6);
    ListPrintf(p_head);
    return;
}
// void TestByPointer()
// {
//     ListNode *p_head = nullptr;
//     addTotail(&p_head, 3);
//     addTotail(&p_head, 4);
//     addTotail(&p_head, 5);
//     addTotail(&p_head, 6);
//     addTotail(&p_head, 7);
//     addTotail(&p_head, 8);
//     addTotail(&p_head, 9);
//     ListPrintf(&p_head);
//     RemoveNode(&p_head, 6);
//     ListPrintf(&p_head);
//     return;
// }