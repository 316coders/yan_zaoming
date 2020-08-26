//
// Created by z on 2020/8/22.
//

#include "dijkstra.h"
void dijkstra_min_path(vertex s ){ //输入所有的顶点集
    while (1){
        //dist[w] 这个数组表示 s到w的最短距离
        //dist[s] = 0  还有visited[]这个标记的作用
        //V = 没有收录的顶点集 中的最小者；
        //path[w] 记录下来路径 表示s到w的路上金国的某顶点
        if (这样的V 不存在)
            break;
        collected[v] = true;//表示收录了进去

        //然后我们看这个收录点的每个邻接点 w
        for (V 的每个邻接点 w){
            if (collected[w] == false) //如果这个点没有收录进去 则判断操作一波
            {
                if (dist[v] + Edge[v,w]   <  dist [w]){
                    dist[w] = dist[v] + Edge[v,w];
                    path[w] = v;
                }
            }
        }

    }

}