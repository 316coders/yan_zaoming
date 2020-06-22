/* 给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
 二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
输入：[3,2,1,6,0,5]
输出：返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
*/ 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int length = nums.size();
        return construct(nums, 0, length);
    }

private:
    TreeNode* construct(vector<int>& nums, int left, int right){
        if(left == right){
            return NULL;
        }else{
            int index = find_max_index(nums, left, right);
            TreeNode* root = new TreeNode;
            root->val = nums[index];
            int right_new = index;
            root->left = construct(nums, left, right_new);
            int left_new = index+1;
            root->right = construct(nums, left_new, right);
        
        return root;
        }
    }


    int find_max_index(vector<int> nums, int left, int right){
        int max = -1;
        int index_max = -1;
        int i = left;
        for(i; i < right; i++){
            if(max < nums[i]){
                max = nums[i];
                index_max = i;
            }
        }
        return index_max;
    }
};

