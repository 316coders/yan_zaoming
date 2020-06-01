/*设计一个算法，找出数组中两数之和为指定值的所有整数对。
一个数只能属于一个数对。
输入: nums = [5,6,5,6], target = 11
输出: [[5,6],[5,6]]
*/

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> ans;
         int n = nums.size();
        unordered_map<int, int> m;
        for (auto n : nums)
            m[n]++;
            //全部过滤 计数
        
         for(int i = 0; i < n; i++)
        {
            if(m[nums[i]])
            {
                m[nums[i]]--;
                if(m[target - nums[i]]) 
                //在map 两个键 相减 刚好存在另一个健，那么着两个健对匹配成功
                {
                    ans.push_back({nums[i], target - nums[i]});
                    m[target - nums[i]]--;
                }
            }
        }

        //for (auto n : nums)
        //   if (--mp[n] >= 0 && --mp[target - n] >= 0)
        //    {   //--mp[n], --mp[target - n];
        //       ans.push_back({n, target - n});
        //    {n,target-n} 这样为一个vector    
        //    }
        return ans;


    }
};