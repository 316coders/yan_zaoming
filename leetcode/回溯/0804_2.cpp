/* 第二种方法，我们使用队列的方式
 * 不再使用栈和递归的方式
 * 
 */
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;
class Solution
{
private:
public:
    Solution();
    ~Solution();
    vector<vector<int>> subsets(vector<int> &nums);
};

Solution::Solution()
{
}

Solution::~Solution()
{
}



vector<vector<int>> Solution::subsets(vector<int> &nums)
{
    queue<vector<int>> que;
    vector<vector<int>> res;
    unordered_map<int,int> m;
    for(int i = 0; i < nums.size(); ++i){
        m[nums[i]] = i+1;
    }
    que.push({});
        
    while(!que.empty()){
        auto temp = que.front();
        que.pop();
        res.push_back(temp);
        int i = 0;
        if(!temp.empty()) i = m[temp.back()];
        for(; i < nums.size(); ++i){
            temp.push_back(nums[i]);
            que.push(temp);
            temp.pop_back();
        }
    }
    return res;
}