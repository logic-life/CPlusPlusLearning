#include "createtree.h"
bool preOrder(TreeNode *root);
void test();

int main(void)
{
    test();
    
    return 0;
}

void test(){
    vector<int> vec = {1, 3, 5, NULL, NULL, 9, 10};
    TreeNode *root = nullptr;
    root=createTree(root,vec);
    preOrder(root);
    return;
}

bool preOrder(TreeNode *root)
{
    if (root == nullptr)
        return false;
    else
    {
        cout << root->val;
        preOrder(root->left);
        preOrder(root->right);
    }
    return true;
}