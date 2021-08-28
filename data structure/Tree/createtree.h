#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
//深度
extern int depth;
//当前层数
extern int cur;
struct TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void addNode(vector<TreeNode> &vec, int i, int n)
{
    if (2 * i + 2 > n)
        return;
    vec[i].left = &vec[2 * i + 1];
    vec[i].right = &vec[2 * i + 2];
    return;
}
//按照层序遍历创建一个二叉树
//有问题，向量的回收机制会释放内存导致野指针
TreeNode *createTree(TreeNode *root, vector<int> vec)
{
    //创建与只对应的二叉树节点个数
    vector<int>::size_type sz = vec.size();
    TreeNode node;
    if (sz == 0)
        return nullptr;
    vector<TreeNode> tree_node;
    for (vector<int>::size_type i = 0; i < sz; i++)
    {
        node = TreeNode(vec[i]);
        tree_node.push_back(node);
    }
    for (int i = (sz - 2)/2; i >= 0; i--)
        addNode(tree_node, i, sz);
    for (vector<int>::size_type i = 0; i < sz; i++){

    }
        return root;
}