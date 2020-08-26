//
// Created by z on 2020/8/20.
//

#include "graph_bfs.h"

double graph_bfs::maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end) {
        vector<bool> visited(n, false);

        vector<vector<pair<double, int>>> path(n, vector<pair<double, int>>());
        for (int i = 0; i < edges.size(); i++)
        {
            auto& edge = edges[i];
            path[edge[0]].push_back({ succProb[i], edge[1] });
            path[edge[1]].push_back({ succProb[i], edge[0] });
        }
        //建立图的关系
        /* 是一个n * n 的关系图 元素是 一对
         *     0    1   2   3
         * 0--0.5-->1
         * 1--0.5-->0  1--0.5-->2
         * 2--0.5-->1
         * 3
         */

        priority_queue<pair<double, int>> pq;
        pq.push({ 1, start });

        while (!pq.empty()) {
            auto [curProb, cur] = pq.top();
            pq.pop();

            if (visited[cur]) continue;
            visited[cur] = true;

            if (cur == end) return curProb;

            for (auto [nextProb, next] : path[cur]) {
                if (visited[next]) continue;
                pq.push({ curProb * nextProb, next });
            }
        }
        return 0;
}
