```
#include <iostream>
#include <algorithm>
#include <exception>
using namespace std;
//创建二叉树节点
struct BinaryTreeNode
{
    typedef BinaryTreeNode *BS;
    int value;
    BS tree_left;
    BS tree_right;
    BinaryTreeNode(int val) : value(val), tree_left(nullptr), tree_right(nullptr) {}
    BinaryTreeNode() : value(0), tree_left(nullptr), tree_right(nullptr) {}
};
BinaryTreeNode *ConstructCore(int *prestart, int *preend, int *instart, int *inend);
BinaryTreeNode *Construct(int *preorder, int *inorder, int length)
{ //先序或者后序序列为空
    if (preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;
    else
        return ConstructCore(preorder, preorder + length-1, inorder, inorder + length-1);
}

BinaryTreeNode *ConstructCore(int *prestart, int *preend, int *instart, int *inend)
{
    //创建根节点
    BinaryTreeNode *root = new BinaryTreeNode(*prestart);
    //边界条件，节点数唯一
    if (prestart == preend)
    {
        if (prestart == preend && *prestart == *instart)
            return root;
        else
            throw "Invalid input";
    }
    //找到前序遍历中根节点的位置
    int *rootinorder = find(instart, inend, *prestart);
    //设定左子树的长度为length
    int length = rootinorder - instart;
    //未找到，说明输入有误
    if (rootinorder == inend)
        throw "Invalid input";

    if (length > 0)
        //递归调用，左子树
        root->tree_left = ConstructCore(prestart + 1, prestart + length, instart, rootinorder - 1);
    if (length < preend - prestart)
        //递归调用，右子树
        root->tree_right = ConstructCore(prestart + length + 1, preend, rootinorder + 1, inend);
    //返回生成的树
    return root;
}
```