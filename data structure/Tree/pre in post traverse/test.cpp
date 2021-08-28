#include <iostream>
#include "binarytree.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    BinaryTree tree;
    TreeNode *root = nullptr;
    vector<int> vec = {2, 4, 3, 1, 5, 6, 3, 8};
    for (auto i : vec)
        tree.addLeafNode(root, i);

    return 0;
}