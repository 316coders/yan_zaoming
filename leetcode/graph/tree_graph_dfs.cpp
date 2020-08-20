//
// Created by z on 2020/8/20.
//

#include "tree_graph_dfs.h"

vector<int> tree_graph_dfs::countSubTrees(int n, vector<vector<int>> &edges, string labels) {
    g.resize(n);

    //创建图的邻接矩阵 对图的深度遍历 一个节点 g[0]=[1,2,4] 表示0-1，0-2， 0-4 这几个路径
    for (const auto &edge: edges) {
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }

    //树中每个节点 维护一个26 字母表的数组
    //assign(n,int x) 赋n个值为x的元素到vector容器中，这个容器会清除掉vector容器中以前的内容
    f.assign(n,vector<int>(26));

    //建好图
    dfs(0,-1,labels);

    vector<int> ans;
    ans.reserve(n);
for (int i = 0; i < n; i++) {
        ans.push_back(f[i][labels[i]-'a']);
    }
    return ans;
}

void tree_graph_dfs::dfs(int o, int pre, const string &label) {
    f[o][label[o] - 'a'] = 1; //表示这个节点的  某个字母的个数

    for (const auto &nex : g[o]) {
        //这个循环表示对所有g[o] 所对应的子节点进行深度遍历
        //g[1] = [0,3] 当nex 0 == pre 0 的时候说明这个地方是一个返回路径
        if (nex==pre)
            continue;

        dfs(nex,o,label);

        //对 字母表进行维护
        for (int i = 0; i < 26; ++i) {
            f[o][i] = f[o][i]+f[nex][i];
        }
    }
}
