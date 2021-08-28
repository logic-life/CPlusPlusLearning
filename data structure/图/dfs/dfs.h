#include <iostream>
#include <stack>
using namespace std;

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

int maxDepth(TreeNode *root)
{
    int depth = 0;
    stack<TreeNode *> visited;
    //当根节点为空时，此时最长路径为0
    if (root == nullptr)
        return 0;
    //不为空时，将根节点设置为已经访问
    visited.push(root);
    depth++;
    //选择子节点中的最长路径
    depth = depth + max(maxDepth(root->left), maxDepth(root->right));
    return;
}