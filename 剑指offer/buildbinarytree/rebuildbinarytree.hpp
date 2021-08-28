#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
using namespace std;
//创建二叉树节点
struct TreeNode
{
    typedef TreeNode *BS;
    int value;
    BS left;
    BS right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
    TreeNode() : value(0), left(nullptr), right(nullptr) {}
};
TreeNode *ConstructCore(vector<int>::iterator prestart, vector<int>::iterator preend,
                        vector<int>::iterator instart, vector<int>::iterator inend);
TreeNode *Construct(vector<int> &preorder, vector<int> &inorder)
{ //先序或者后序序列为空
    if (preorder.size()==0 || inorder.size()==0)
        return nullptr;
    else
        return ConstructCore(preorder.begin(), preorder.end()-1, inorder.begin(), inorder.end()-1);
}

TreeNode *ConstructCore(vector<int>::iterator prestart, vector<int>::iterator preend,
                        vector<int>::iterator instart, vector<int>::iterator inend)
{
    //创建根节点
    TreeNode *root = new TreeNode(*prestart);
    //边界条件，节点数唯一
    if (prestart == preend)
    {
        if (prestart == preend && *prestart == *instart)
            return root;
        else
            throw "Invalid input";
    }
    //找到前序遍历中根节点的位置
    vector<int>::iterator rootinorder = find(instart, inend, *prestart);
    //设定左子树的长度为length
    int length = rootinorder - instart;
    //未找到，说明输入有误
    if (rootinorder == inend+1)
        throw "Invalid input";

    if (length > 0)
        //递归调用，左子树
        root->left = ConstructCore(prestart + 1, prestart + length, instart, rootinorder - 1);
    if (length < preend - prestart)
        //递归调用，右子树
        root->right = ConstructCore(prestart + length + 1, preend, rootinorder + 1, inend);
    //返回生成的树
    return root;
}