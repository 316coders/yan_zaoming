/*  
 * 
 * 输入：root1 = [1,2,3,4,5,6,null,null,null,7,8], 
 * root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
 * 输出：true
 * 
 * 解释：我们翻转值为 1，3 以及 5 的三个节点。 
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
/* 当时想用层次遍历
 * 后来  发现，，，深度遍历也可以。
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        if (root1 == nullptr && root2 == nullptr)
        {
            return true;
        }
        else if (root1 == nullptr || root2 == nullptr || root1->val != root2->val)
        {
            return false;
        }
        
        //root1、root2都非空，且值相等
        //
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) 
                ||
                flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};
