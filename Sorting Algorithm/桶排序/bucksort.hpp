#include <iostream>

using namespace std;

struct ListNode
{
    explicit ListNode(int i = 0) : mData(i), mNext(NULL) {}
    ListNode *mNext;
    int mData;
};

ListNode *insert(ListNode *head, int val)
{
    ListNode dummyNode;
    ListNode *newNode = new ListNode(val);
    ListNode *pre, *curr;
    dummyNode.mNext = head;
    pre = &dummyNode;
    curr = head;
    while (NULL != curr && curr->mData <= val)
    {
        pre = curr;
        curr = curr->mNext;
    }
    newNode->mNext = curr;
    pre->mNext = newNode;
    return dummyNode.mNext;
}
