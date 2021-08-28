#include "staticbinarytree.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    TreeNode *root;
    BinaryTree tree;
    tree.create(root);
    cout << endl;
    tree.preOrder(root);
    cout << endl;
    tree.inOrder(root);
    cout << endl;
    tree.postOrder(root);
    cout << endl;
    return 0;
}