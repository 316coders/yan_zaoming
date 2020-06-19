/* 编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。 
 * 说明：解集不能包含重复的子集。
 * 输入 nums=[1,2,3];
 * 输出
 *  输出：
 * [[3],[1],[2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []]
 * */
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //首先我们的开始位置是一个空集 [] 待选集合是 nums
        //其中需要注意的是 set集合的应用
       
        vector<int> current_nums;
        backtrack(nums, current_nums);
        result.push_back({}); //表示 [];
        return result;
    }


    bool is_satisied(vector<int> curent_nums, int element){
        vector<int>::iterator iter = find(curent_nums.begin(),curent_nums.end(), element);  
        if(iter != curent_nums.end()){
            return false;
        }
        if(iter == curent_nums.end()){
            return true;
        }
    }

    bool is_repeated(vector<int> curent_nums, int element, vector<vector<int>> result){
        curent_nums.push_back(element);
        sort(curent_nums.begin(), curent_nums.end());
        int len = result.size();
        for(int i =0; i< len; i++){
            sort(result[i].begin(), result[i].end());
            if(curent_nums==result[i])
                return false;
        }
        return true;
    }

    void backtrack(vector<int> &nums, vector<int> &curent_nums){
        if(curent_nums.size() >= nums.size())
            return;
        for(int i=0; i < nums.size(); i++){
            if( is_satisied(curent_nums, nums[i]) && is_repeated(curent_nums, nums[i], result)){
                //说明排除了 1，1，1这样的数组
                //还有一个问题： 是否与result里面的的元素重复 判断
                curent_nums.push_back(nums[i]);
                result.push_back(curent_nums);
            }   //注意continue的位置
            else
            {
                continue;
            }
            backtrack(nums,curent_nums);
            curent_nums.pop_back();
        }

    }
};

int main(){
    Solution s;
    int a[] = {1,2,3};
    vector<int> nums(a,a+3);
    vector<vector<int>> res;
    res = s.subsets(nums);
    return 0;
}
