/* 最大子数组
 * 使用数学归纳法 利用dp[i] 推出dp[i+1]
 * 定义dp数组 是以nums[i] 为结尾的[最大子数组和]为dp[i]
 * 
 * 
 */

#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        // dp[i] 表示以 nums[i]为结尾子数组的最大值。

        dp.push_back(nums[0]);
        
        for(int i =1; i < nums.size(); i++){
            int temp = dp[i-1] + nums[i];
            if(temp > nums[i]){
                dp.push_back(temp);
            }else{
                dp.push_back(nums[i]);
            }
        }

        auto res = max_element(dp.begin(), dp.end());
        return *res;
    }
};

int main(){
    Solution s;
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v(a,a+9);
    int b = s.maxSubArray(v);
    cout<<b<<endl;

    return 0;
}