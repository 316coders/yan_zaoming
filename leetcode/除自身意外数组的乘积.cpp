/*
输入: [1,2,3,4]
输出: [24,12,8,6]

使用了除法，程序效率低下。
多开辟内存，也要避免除法。
也能通过，耗时有点高，26ms.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        map<int,int> hash_t1;
        vector<int> zeros_index;
        vector<int> res(nums.size(),0);

        for(int i=0; i < nums.size(); i++){
            hash_t1[nums[i]]++; 
            if(nums[i] == 0){
                zeros_index.push_back(i);
            }
        }

        if(hash_t1[0] >=2){
            return res;
        }
        else if(hash_t1[0] == 1){
            nums[zeros_index[0]] = 1;
            int mults=1;
            for (auto i : nums){
                mults = mults*i;
            }
            res[zeros_index[0]] = mults;
            return res;
        }
        else{
            int mults=1;
            for (auto i : nums){
                mults = mults*i;
            }

            for(int i=0; i < nums.size(); i++){
                int temp = mults/nums[i];
                res[i] = temp;
            }
            return res;
        }

    }
};


//官方题解  使用左右两个数组进行记录 O(3n)
//   [2,4,1,3,5]
//前 [1,2,8,8,24]
//后 [60,15,15,5,1]
//对应相乘
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();

        // L 和 R 分别表示左右两侧的乘积列表
        vector<int> L(length, 0), R(length, 0);

        vector<int> answer(length);

        // L[i] 为索引 i 左侧所有元素的乘积
        // 对于索引为 '0' 的元素，因为左侧没有元素，所以 L[0] = 1
        L[0] = 1;
        for (int i = 1; i < length; i++) {
            L[i] = nums[i - 1] * L[i - 1];
        }

        // R[i] 为索引 i 右侧所有元素的乘积
        // 对于索引为 'length-1' 的元素，因为右侧没有元素，所以 R[length-1] = 1
        R[length - 1] = 1;
        for (int i = length - 2; i >= 0; i--) {
            R[i] = nums[i + 1] * R[i + 1];
        }

        // 对于索引 i，除 nums[i] 之外其余各元素的乘积就是左侧所有元素的乘积乘以右侧所有元素的乘积
        for (int i = 0; i < length; i++) {
            answer[i] = L[i] * R[i];
        }

        return answer;
    }
};
