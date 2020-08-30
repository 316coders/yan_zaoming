#include <iostream>
#include "tree.h"
#include "two_tree_parent.h"
#include "BFS.h"
using namespace std;

TreeNode* DFS(TreeNode*, int[], int&);

int main() {
    int index = 0;
    int  befor_bianli [6] = {1,2, 0,0, 4, 5};
    TreeNode * root = new TreeNode(befor_bianli[index]);
    index = index+1;

    root->left = DFS(root->left, befor_bianli, index);
    root->right = DFS(root->right, befor_bianli, index);

    BFS* bfs = new BFS();
    string aa = bfs->serialize(root);
    cout<<aa<<endl;

    return 0;
}

TreeNode* DFS(TreeNode * node, int befor_nums[], int &index){
    if(befor_nums[index] != 0 && index < 6){
        TreeNode * tree_node = new TreeNode(befor_nums[index]);
        index = index+1;
        tree_node->left = DFS(tree_node->left, befor_nums, index);
        tree_node->right = DFS(tree_node->right, befor_nums, index);
        return tree_node;
    } else{
        index = index+1;
        return NULL;
    }
}
