#include <iostream>

using namespace std;

struct QueueNode
{ //定义一个队列节点
    /* data */
    int val;
    QueueNode *next;
    QueueNode() : val(0), next(nullptr) {}
    QueueNode(int x, QueueNode *next) : val(0), next(next) {}
};

class MyCirclarQueue
{
private:
    QueueNode *root_node;
    QueueNode *head;
    QueueNode *tail;
    int queue_length;

public:
    MyCirclarQueue(int k);
    bool enQueue(int value);
    bool deQueue();
    bool isEmpty();
    bool isFull();
    int Rear();
    ~MyCirclarQueue();
};

MyCirclarQueue::MyCirclarQueue(int k)
{ //记队列长度为k
    queue_length = k;
    //如果k大于1时，创建队列
    if (k >= 1)
    { //创建一个队列节点
        tail = head = root_node = new QueueNode();
        for (int i = 0; i < k - 1; i++)
        { //再次创建一个队列节点
            QueueNode *node = new QueueNode();
            //将当前节点的next指向下一个节点，并且将tail移动到下一个节点
            tail->next = node;
            tail = tail->next;
        }
        tail->next = root_node;
        //将尾节点重新移到头结点的位置
        tail = head;
    }
}

bool MyCirclarQueue::enQueue(int value)
{
    if (isFull() == true)
        return false;
    else
    {
        tail->val = value;
        tail = tail->next;
        return true;
    }
}

bool MyCirclarQueue::deQueue()
{
    if (isEmpty() == true)
        return false;
    else
    {
        head->val = 0;
        head = head->next;
        return true;
    }
}

int MyCirclarQueue::Rear()
{
    if (isEmpty() != true)
        return head->val;
}

bool MyCirclarQueue::isEmpty()
{
    auto p = head;
    auto q = tail;
    if (p == q && p->val == 0)
        return true;
    return false;
}

bool MyCirclarQueue::isFull()
{
    auto p = head;
    auto q = tail;
    if (p == q)
        return false;
    else
    {
        while (p != q)
        {
            if (p->val != 0)
                p = p->next;
            return false;
        }
        if (p->val != 0)
            return true;
        else
            return false;
    }
}

MyCirclarQueue ::~MyCirclarQueue()
{
    auto p = root_node->next;
    auto q = p;
    for (; p != root_node;)
    {
        q = p->next;
        delete p;
        p = q;
    }
    delete root_node;
}