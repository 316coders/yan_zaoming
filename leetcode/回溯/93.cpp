#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
private:
    vector<string> res;
public:
    //判断与剪枝的条件
    bool isValid(string ip)
    {   
        int val = stoi(ip);
        if(val > 255)
            return false;
        if(ip.size() >= 2 && ip[0]=='0')
            return false;
        return true;
    }

    vector<string> restoreIpAddresses(string s) 
    {
        //记录路径
        vector<string> res;
        vector<string> path;
        int s_pisiton=0;

        //初始情况
        if(s.size() ==0 || s.size() < 4)
            return res;
        
        //存储从根开始到叶子节点的满足条件路径，
        //因为最多3位数字一组。
        //所以同一层横向循环是尝试最多3位的长度
        backtrack(s, 0, path, res);
        return res;
    }

//路径： 记录在 track 当中
//选择列表： s 当中不存在与 track 中的那些元素
//结束条件： s 中的元素全部都在 track 中出现了
/*
1 终止条件 有几个，写在backtrack的开始部分
2 for 横向循环， pos记录当前位置，i记录取几个
3     横向循环第一个元素的时候  判断是否是有效值
4         有效的话 压入栈中
5          backtrack 
6       return; pop_back();
*/
    void backtrack(string &s, int pos, vector<string> &path, vector<string> &res)
    {   
        //我们把 “255.”作为一个string push_back到res中。
        //首先判断剩余的位数，是不是还能满足要求，
        //触发结束条件
        int maxLen = (4-path.size()) *3;//剩下最多可以放几个 2.xxx.xxx.xxx
        if(s.size() - pos > maxLen)//如果剩下的数字依然大于maxLen，则return
            return;
        if(path.size()==4 && pos==s.size())
        //已经放入了4个 xxx.xxx.xxx.xxx
        //触发满足条件，把path存储到res 中。
        {   
            string ans = "";
            for(int i=0; i < 4; ++i){
                ans += path[i];
                if(i!=3)
                    ans+=".";
            }
            res.push_back(ans);
            return;
        }
        
        //循环加递归，回溯法的经典 表示横向循环， backtrak之后i变成2
        for(int i = pos; i < s.size() && i<=pos+2; ++i){
            string ip = s.substr(pos, i-pos+1);
            
            // 排除不合法的选择
            if(!isValid(ip))
                continue;

            path.push_back(ip);

            //进入下一层决策树
            backtrack(s, i+1, path, res);

            //取消选择
            path.pop_back();
        }
    }
};


int main(){
    Solution s;
    string str = "2551692550";
    s.restoreIpAddresses(str);

    return 0;
}