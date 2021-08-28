#pragma once
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left_node;
    TreeNode *right_node;
    TreeNode() : val(0), left_node(nullptr), right_node(nullptr) {}
    TreeNode(int x) : val(x), left_node(nullptr), right_node(nullptr) {}
    TreeNode(int x, TreeNode *left_node, TreeNode *right_node) : val(x), left_node(left_node), right_node(right_node) {}
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
    bool preOrder(TreeNode *root);
    //后序遍历
    bool postOrder(TreeNode *root);
    //中序遍历
    bool inOrder(TreeNode *root);

    void create(TreeNode *&root);

    ~BinaryTree();
};

void BinaryTree::create(TreeNode *&root)
{
    root = new TreeNode(2);
    TreeNode *tree_node_1 = new TreeNode(3);
    TreeNode *tree_node_2 = new TreeNode(4);
    TreeNode *tree_node_3 = new TreeNode(5);
    TreeNode *tree_node_4 = new TreeNode(6);
    TreeNode *tree_node_5 = new TreeNode(7);
    TreeNode *tree_node_6 = new TreeNode(8);
    root->left_node = tree_node_1;
    root->right_node = tree_node_4;
    tree_node_1->left_node = tree_node_2;
    tree_node_1->right_node = tree_node_3;
    tree_node_4->left_node = tree_node_5;
    tree_node_4->right_node = tree_node_6;
}
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
        addLeafNode((val < root->val ? root->left_node : root->right_node), val);
        return;
    }
}
//前序遍历
bool BinaryTree::preOrder(TreeNode *root)
{
    if (root == nullptr)
        return false;
    else
    {
        cout << root->val;
        preOrder(root->left_node);
        preOrder(root->right_node);
    }
    return true;
}

bool BinaryTree::inOrder(TreeNode *root)
{
    if (root == nullptr)
        return false;
    else
    {
        inOrder(root->left_node);
        cout << root->val;
        inOrder(root->right_node);
    }
    return true;
}

bool BinaryTree::postOrder(TreeNode *root)
{
    if (root == nullptr)
        return false;
    else
    {
        inOrder(root->left_node);
        inOrder(root->right_node);
        cout << root->val;
    }
    return true;
}
BinaryTree::~BinaryTree()
{
}
