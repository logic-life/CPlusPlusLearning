#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTree
{
private:
    /* data */
    TreeNode *root;

public:
    BinaryTree(/* args */) : root(nullptr) {}
    //添加叶子节点
    void addLeafNode(TreeNode *&root, const int val);
    //删除叶子节点
    void deleteLeafNode(TreeNode *&root);
    //前序遍历
    void preOrder(TreeNode *root);

    //后序遍历
    bool postOrder(TreeNode *root);
    //中序遍历
    bool inOrder(TreeNode *root);
    //非递归实现中序
    bool inOrderByStack(TreeNode *root);
    ~BinaryTree();
};

void BinaryTree::addLeafNode(TreeNode *&root, const int val)
{

    //判断根节点是否为空，如果是的话，创建一个根节点
    if (root == nullptr)
    {
        root = new TreeNode(val);
        return;
    }
    else
    { //如果添加的值比父节点小，就添加在左节点，否则就添加在右节点
        addLeafNode((val < root->val ? root->left : root->right), val);
        return;
    }
}

bool BinaryTree::inOrder(TreeNode *root)
{
    if (root == nullptr)
        return false;
    else
    {
        inOrder(root->left);
        cout << root->val;
        inOrder(root->right);
    }
    return true;
}

bool inOrderByStack(TreeNode *root)
{
    TreeNode *node = root;
    stack<TreeNode *> s_node;
    while (node != nullptr || !s_node.empty())
    { //只要节点不为空就将其压栈
        while (node != nullptr)
        {
            s_node.push(node);
            node = node->left;
        }
        //只要栈不为空，就打印栈顶元素将其指向右子树后并删除
        if (!s_node.empty())
        {
            cout << s_node.top() << " ";
            node = s_node.top()->right;
            s_node.pop();
        }
    }
}

bool BinaryTree::postOrder(TreeNode *root)
{
    if (root == nullptr)
        return false;
    else
    {
        inOrder(root->left);
        inOrder(root->right);
        cout << root->val;
    }
    return true;
}
BinaryTree::~BinaryTree()
{
}
