# 算法框架
```
int BFS(Node start,Node target){
    Queue<Node> q;//核心数据结构
    Set<Node> visited;//避免走回头路

    q.push(start);
    visited.add(start);

    while(q not empty){
        int sz=q.size();
        for(int i=0;i<sz;i++)
        {
            Node cur=q.front();
            q.pop();
            if( cur is target)
                return step;
                //添加相邻节点
            for(Node x:cur.adj)
                if(x not in visited){
                    q.push(x);
                    visited.add(x);
                }
        }
        //更新步数
    step++;
    }
}
```