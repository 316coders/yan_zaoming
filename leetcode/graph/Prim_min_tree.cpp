//
// Created by z on 2020/8/22.
//
void Prim(){
    MST = {s};//先找到一个最小生成树的根节点
    parent[s] = -1; //定义为-1 初始化表明为根节点
    while (1){
        v = 未被收录顶点dist最小者;
        dist[v]应该初始化为正无穷;
        dist是顶点v到最小生成树的最小距离;
        if (这样的V不存在)
            break;
        将v收录进MST; dist[v] = 0;//表明这个顶点距离树为0 被收录进去
        for (V的每个邻接点W){
            if (w未被收录  dist[w]!=0){ //说明没有存在环路
                if (Edges[v,w] < dist[w]){
                    //如果说v-w存在一条边  距离小于原本w到树的距离
                    //那么我们就进行 w到树的距离
                    dist[w] = Edges[v,w];
                    parent[w] = v;// v是w 的一个parent
                }
            }
        }
    }

    //跳出的时候 要看一下图是否是联通的
    if( MST 中收的顶点不到|V| 个){
        Error("生成树不存在");
    }

}
