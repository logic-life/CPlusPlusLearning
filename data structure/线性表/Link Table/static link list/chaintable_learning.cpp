#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} Node;

int main(int argc, char *argv[])
{
    Node node_1 = {10, nullptr};
    Node node_2 = {20, nullptr};
    Node node_3 = {30, nullptr};
    Node node_4 = {40, nullptr};
    Node node_5 = {50, nullptr};
    Node node_6 = {60, nullptr};
    Node node_7 = {70, nullptr};
    Node node_8 = {80, nullptr};
    node_1.next = &node_2;
    node_2.next = &node_3;
    node_3.next = &node_4;
    node_4.next = &node_5;
    node_5.next = &node_6;
    node_6.next = &node_7;
    node_7.next = &node_8;
    node_8.next = nullptr;
    Node *pointer_current = &node_1;
    for (; pointer_current; pointer_current = pointer_current->next)
    {
        cout << "输出地址：" << pointer_current << "输出当前链表数据：" << pointer_current->data << endl;
    }
    return 0;
}