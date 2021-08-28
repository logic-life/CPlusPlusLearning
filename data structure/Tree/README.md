# 树

性质1：二叉树的第i层最多有$2^{i-1}$个结点，以下性质都是建立在根节点所在层为第1层的基础上。

性质2：深度为k的二叉树至多有$2^{k}-1$个结点。

性质3：对于任何一棵二叉树T若其叶子节点的数量为$n_0$，度为2的结点数为$n_2$,则$n_0=n_2+1$。

满二叉树：深度为K,结点数为$2^k-1$,称之为满二叉树。

完全二叉树：如果深度为K的二叉树，第k-1层为满二叉树，最下面一层结点都集中在最左边，则称此二叉树为完全二叉树。

性质4：具有n个结点的完全二叉树深度为向下取整$logn$+1。

二叉树层序遍历模板：

```
int minDepth(TreeNode *root)
{   
    // 二叉树的层序遍历
    TreeNode * cur=root;
    // 依据题意换成需要的参数
    ......
    queue<TreeNode *> my_queue;
    if(root==nullptr)
        return ...;
    my_queue.push(root);
    while(!my_queue.empty())
    {
        int size=my_queue.size();
	// 依据题意更换成需要的参数
        .......
        for(int i=0;i<size;i++)
        {
            cur=my_queue.front();
            my_queue.pop();
            if(cur->left) my_queue.push(cur->left);
            if(cur->right) my_queue.push(cur->right);
            ......
        }
    }
    return ...;
}
```
