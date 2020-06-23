/*给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * 输出: 6 
 * 解释: 节点 2 和节点 8 的最近公共祖先是 6。
 * 
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * 输出: 2
 * 解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 发现有关二叉树问题，可能需要树中任意位置，
 * 比如某条不以root起始的路径，公共节点，可以对二叉树进行两重遍历，
 * 就像经常写两个for循环一样。
 * 不过没有利用到二叉搜索树的特点。
 * /
 * 
 /**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == p || root == q) return root;
        bool lp = exists(root.left, p);
        bool lq = exists(root.left, q);
        bool rq = exists(root.right, q);
        bool rp = exists(root.right, p);
        if( (lp&&rq) || (lq&&rp)) return root;
        if(lp&&lq) return lowestCommonAncestor(root.left,p,q);
        if(rp&&rq) return lowestCommonAncestor(root.right, p, q);
        return null;
    }

    bool exists(TreeNode root, TreeNode val){
        if(root == null) return false;
        if(root == val) return true;
        return exists(root.left, val) || exists(root.right, val);
    }
}
 

