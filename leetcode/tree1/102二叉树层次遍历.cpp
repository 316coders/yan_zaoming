#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;
        if (!root) return ret;

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            //这个控制层数 也可以用于多叉树的遍历
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) {

                auto node = q.front();
                q.pop();
                //这个auto 类型， 避免了 TreeNode*->int 与指针的比较
                ret.back().push_back(node->val);
                //从ret当中返回一个末尾元素vector<>类型
                //然后用这个vector<>来push_back();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ret;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int>   tree_node_value;

        tree_node_value.push_back(root->val);
        result.push_back(tree_node_value);

        queue<TreeNode*> tree_queue;
        tree_queue.push(root->left);
        tree_queue.push(root->right);
        

        while(!tree_queue.empty())
        {   vector<int> layer_val;
            auto temp_left = tree_queue.front();
            if(temp_left->val)
                layer_val.push_back(temp_left->val);
            tree_queue.pop();

            auto temp_right = tree_queue.front();
            if(temp_right->val)
                layer_val.push_back(temp_right->val);
            tree_queue.pop();

            result.push_back(layer_val);

            tree_queue.push(temp_left->left);
            tree_queue.push(temp_left->right);
            tree_queue.push(temp_right->left);
            tree_queue.push(temp_right->right);
        }

        return result;
    }
};



int main(){
    int a[5] = {3,9,20,15,7};
    TreeNode * node = (TreeNode*)malloc(sizeof(TreeNode)*2 + sizeof(int));


    return 0;
}