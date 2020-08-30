/* 
 * 实现一个函数，检查二叉树是否平衡。在这个问题中， 
 * 平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。
 * 示例 1:给定二叉树 [3,9,20,null,null,15,7]
    3
   / \
  9  20
    /  \
   15   7 返回 true 。
 * 示例 2:给定二叉树 [1,2,2,3,3,null,null,4,4]
      1
     / \
    2   2
   / \
  3   3
 / \
4   4返回 false 
 * /

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
private:
bool isbalance = true;

public:
    bool isBalanced(TreeNode* root) {
        int aa = DFS_height(root);
        return isbalance;
    }

    int DFS_height(TreeNode* root){
        //递归结束的条件 也就是叶子节点的条件
        if(root!=NULL){
            //表示每一步移动需要做什么操作
            int left_height = 1 + DFS_height(root->left);
            int right_height = 1+ DFS_height(root->right);

            //一个子树结束后 需要做什么操作与判断
            if(abs(left_height-right_height) > 1){
                isbalance = false;
            }
            return max(left_height,right_height);
        }
        return -1;
    }
};