//
// Created by z on 2020/8/20.
//

#include <iostream>
#include "graph_dfs.h"

double graph_dfs::maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end) {
    double rate = 0;     //存储最终的结果
    double maxRate = 0;

    //相当于构建一个图 边和权重的关系 双向图
    for (int i = 0; i < edges.size(); i++) {  //
        //将第一个节点做key 第二个节点做数组元素的first值，节点间的权值做数组元素的second值
        this->mp[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
        this->mp[edges[i][1]].emplace_back(edges[i][0], succProb[i]);

        if (succProb[i] > maxRate)
            maxRate = succProb[i]; //记录最大概率，用作边界条件判断
    }
    /* mp pair 表示一对
     *  0  {1:0.5}  0--->1
     *     {2:0.2}  0--->2
     *
     *  1  {0:0.5}  1--->0
     *     {2:0.5}  1--->2
     *
     *  2  {1:0.5}  2--->1
     *     {0:0.2}  2--->0
     */

    st[start] = 1; //加上，防止重复访问
    def(start, end, rate, 1, maxRate);

    return rate;
}

void graph_dfs::def(int start, int end, double &rate, double temp, double maxRate) {
    //使用map 数组，这里只需要遍历相关节点
    for(int i; i < mp[start].size(); i++){
        printf("%d  %s  %d",start,"+++++",mp[start][i].first);
        auto p = mp[start][i];
        if (!st[p.first]){
            //判断是否访问过该节点
            temp = temp * p.second; //权值相乘 获取到该节点的概率
            if (p.first == end)//边界判断
            {
                if(temp > rate)
                    rate = temp;
                temp = temp/p.second;  //看是否要接受这个点，不接受的话要退回 撤销操作
                continue;
            }
            if (temp < 1e-5 || temp * maxRate < rate){
                temp = temp/p.second;
                continue;
            }

            st[p.first] = 1; //标记已经遍历（执行操作）

            cout<<"%%:"<<p.first <<"-"<<st[p.first]<<endl;

            def(p.first, end,rate,temp, maxRate);//递归获取下一批节点

            //回溯操作
            temp = temp/p.second; //撤销操作
            st[p.first] = 0; //撤销操作
        }

    }
}
