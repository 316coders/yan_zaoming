/* 300. 最长上升子序列
 * 输入: [10,9,2,5,3,7,101,18] 
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 
 * 使用自然归纳法 设计动态规划 需要一个DP 数组
 * 定义 dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度 
 *         ***表示哪个状态 如何设计***
 * nums 1,4,5,4,2,3
 * dp   1,2,3,2,2     dp[5] = dp[4]+1 if nums[5] > nums[4]
 *                            dp[] +1 先前找到一个比nums[5]小的数字  
 */

#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        vector<int> dp(nums.size(),1);

        for(int i=0; i <nums.size(); i++){
            for(int j =0; j<i; j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }

        int res=0;
        for(int i=0; i < dp.size(); i++){
            res = max(res, dp[i]);
        }
        return res;

    }
};
