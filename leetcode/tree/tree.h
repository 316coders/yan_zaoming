//
// Created by z on 2020/8/28.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};

#endif //TREE_TREE_H
