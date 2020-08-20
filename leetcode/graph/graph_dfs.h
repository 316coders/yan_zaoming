//
// Created by z on 2020/8/20.
//

#ifndef INC_8_20_GRAPH_DFS_H
#define INC_8_20_GRAPH_DFS_H
#include "vector"
#include "string"
#include <cstdio>

using namespace std;

/* edges = [[0,1],[1,2],[0,2]],
 * succProb=[0.5, 0.5,   0.2]
 * start = 0
 * end = 2
 *
 * 我们采用回溯算法+剪枝
 */


class graph_dfs {
private:
    vector<pair<int, double>> mp[10005];
    int st[10005];

public:
    double  maxProbability(int n, vector<vector<int>> & edges, vector<double>& succProb, int start, int end);
    void def(int start, int end, double &rate, double temp, double maxRate);
};


#endif //INC_8_20_GRAPH_DFS_H
