#include <iostream>

using namespace std;

struct Node
{
    Node *next;
    int val;
    Node(int x) : val(x), next(nullptr) {}
    Node() : val(0), next(nullptr) {}
};
//在第i个位置添加节点x
void addNode(int i, int x,Node *root);

int main(int argc, char *argv[])
{
    Node *node1 = new Node(3);
    Node *node2 = new Node(4);
    Node *node3 = new Node(6);
    node1->next = node2;
    node2->next = node3;
    addNode(2,5,node1);
    return 0;
}

void merge(Node ){}