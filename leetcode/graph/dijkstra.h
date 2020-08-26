//
// Created by z on 2020/8/22.
//

#ifndef INC_8_20_DIJKSTRA_H
#define INC_8_20_DIJKSTRA_H


class dijkstra {
private:

    void dijkstra_min_path(vertex s ){ //输入所有的顶点集
        while (1){
            //V = 没有收录的顶点集 中的最小者；
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
};


#endif //INC_8_20_DIJKSTRA_H
