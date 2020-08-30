//
// Created by z on 2020/8/28.
//

#include "two_tree_parent.h"

TreeNode *two_tree_parent::lowestCommenAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    /* 临界条件
     * 1 递归 首先考虑判断是否为空
     * 2 看题目意思 再以root 为根节点的树中找到p,q节点的最近公共祖先
     * 第一种情况：左子树和右子树均找没有p结点或者q结点；
     * （这里特别需要注意，虽然题目上说了p结点和q结点必定都存在，但是递归的时候必须把所有情况都考虑进去，
     * 因为题目给的条件是针对于整棵树，而递归会到局部，不一定都满足整体条件）
     * 第二种情况：左子树上能找到，但是右子树上找不到，此时就应当直接返回左子树的查找结果；
     * 第三种情况：右子树上能找到，但是左子树上找不到，此时就应当直接返回右子树的查找结果；
     * 第四种情况：左右子树上均能找到，说明此时的p结点和q结点分居root结点两侧，此时就应当直接返回root结点了。
     */
    if (root->val == p->val || root->val==q->val || root== nullptr){
        return root;
    }
        TreeNode* left = two_tree_parent(root->left, p, q);
        TreeNode* right = two_tree_parent(root->right, p, q);

        //这个地方相当于后序处理
    if (left != nullptr && right == nullptr){
        //左子树找到了，右子树没有找到 返回一个 找到的地址
        return left;
    }
    if (left== nullptr&& right!= nullptr){
        return right;
    }
    if (left== nullptr && right== nullptr)
        return nullptr;
    if (left!= nullptr && right!= nullptr)
        return root;
}
