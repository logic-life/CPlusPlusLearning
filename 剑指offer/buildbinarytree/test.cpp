#include "rebuildbinarytree.hpp"
#include <string.h>
int main(int argc,char *argv[]){
    vector<int> preorder = {1,2};
    vector<int> inorder= {2,1};
    TreeNode *root=Construct(preorder, inorder);
    return 0;
} 