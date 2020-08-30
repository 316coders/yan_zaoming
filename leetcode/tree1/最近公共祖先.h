//
// Created by z on 2020/8/26.
//

#ifndef INC_8_20_最近公共祖先_H
#define INC_8_20_最近公共祖先_H

/* 一般二叉树的公共祖先
 *
 * 1 如果一个节点（root）左子树又两个模板节点中的一个，右子树没有目标节点
 *    那么这个节点肯定不是最近的公共祖先
 * 2 如果一个节点 右子树中又两个目标节点中的一个，左子树没有，
 *    那么这个节点肯定也不是最小的公共祖先
 *  如果我在这个节点中 需要知道左子树和右子树的情况，那么就要后续遍历
 */

class 最近公共祖先 {
public:
    Treenode lowestCommenAncestor(TreeNode root, TreeNode p, TreeNode q){
        //首先考虑一下 递归终止条件
        // 发现了某个节点目标
        if (root== nullptr || root==p || root==q)
            return root;

        //查看左子树中是否又目标节点
        Treenode left = lowestCommenAncestor(root.left, p,q);
        //查看右子树中是否又目标节点
        Treenode right = lowestCommenAncestor(root.right,p,q);

        //都不为空，说明左子树 右子树都又目标节点，则公共祖先就是本身
        if (left!= nullptr && right!= nullptr)
            return root;

        //已经发现了目标节点 则继续向上标记为改目标节点
        return left== nullptr ? right :left;
    }

};


#endif //INC_8_20_最近公共祖先_H
