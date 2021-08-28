#include <iostream>
#include <queue>
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

int minDepth(TreeNode *root)
{ //根节点为空，深度为0
    if (root == nullptr)
        return 0;
    //创建队列，将首元素添加进队列
    queue<TreeNode *> q;
    q.push(root);
    //此时深度为1
    int depth = 1;
    while (!q.empty())
    {
        int sz = q.size();
        //遍历队列中的元素
        for (int i = 0; i < sz; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            //找到深度最小的节点
            if (cur->left == nullptr && cur->right == nullptr)
                return depth;
            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
        }
        depth++;
    }
    return depth;
}