//
// Created by z on 2020/8/28.
//

#include "BFS.h"

string BFS::serialize(TreeNode *root) {
    string ans;

    //BFS 遍历二叉树
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()){
        int queue_size = que.size();
        for (int i = 0; i < queue_size; ++i) {
            TreeNode* node = que.front();
            que.pop();
            if (node != nullptr){
                ans = ans + to_string(node->val);
                //if (node->left!= nullptr)
                    que.push(node->left);
                //if (node->right!= nullptr)
                    que.push(node->right);
            }else{
                //这个地方还需要把空指针标注出来，所以 NULL 也要入队
                ans = ans+"null";
            }
            ans = ans+",";
        }
    }
    return ans;
}

/*
 * 序列化过程 使用bfs遍历整棵二叉树时，将该二叉树转化为一个字符串；
 * 然后反序列化过程 就先调用split函数 将该字符串转为val[0], val[1], val[2]... ，
 * 然后再将这些val给连接成二叉树即可。
 * 1,2,3,null,null,4,5,
 */
vector<string> BFS::split(string& data) {
    int n = data.size();
    vector<string> vec;

    int i=0;
    while(i<n-1){
        string str;
        while(data[i]!=';' || data[i]!=',')
            str+=data[i++];
        vec.push_back(str);
        ++i;
    }
    return vec;
}

TreeNode *BFS::deserialize(string data) {
    //data "[1,2,3,null,null,4,5]" 进行建树
    vector<string> vals = split(data);
    if(vals[0] =="null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(vals[0]));
    queue<TreeNode*> que;//队列辅助构建二叉树；

    que.push(root);

    for (int i = 0; i < vals.size();) {
        if (vals[i] != "null"){
            TreeNode* p = new TreeNode(stoi(vals[i])); //p为指向节点的执政
            que.push(p);
            que.front()->left = p;
        }
        i++;

        if (vals[i] != "null"){
            TreeNode* p = new TreeNode(stoi(vals[i]));
            que.push(p);
            que.front()->right = p;
        }
        i++;
        que.pop();
    }

    return root;
}