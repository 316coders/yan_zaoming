//
// Created by z on 2020/8/28.
//

#ifndef TREE_BFS_H
#define TREE_BFS_H
#include "tree.h"
#include "string"
#include "queue"
#include "vector"
using namespace std;

class BFS {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root);

    vector<string> split(string& data);
    TreeNode* deserialize(string data);
};


#endif //TREE_BFS_H
