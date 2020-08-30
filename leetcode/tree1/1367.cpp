/**
 * Definition for singly-linked list.
 **/ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


#include<vector>
#include<iostream>
using namespace std;

class Solution {
    bool dfs(TreeNode* rt, ListNode* head) {
        // 链表已经全部匹配完，匹配成功
        if (head == NULL) return true;
        // 二叉树访问到了空节点，匹配失败
        if (rt == NULL) return false;
        // 当前匹配的二叉树上节点的值与链表节点的值不相等，匹配失败
        if (rt->val != head->val) return false;
        return dfs(rt->left, head->next) || dfs(rt->right, head->next);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL) return false;
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};


class Solution {
private:
   int list_position = 0;
   stack<ListNode*> stack_1;
   bool flage = false;
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        stack_1.push(head);
        DFS(root);
        return flage;
    }

    void DFS(TreeNode* root){
        if(root == NULL){
            return;
        }

        ListNode* temp = stack_1.top();
        if(temp->next == NULL){
            flage = true;
            return;
        }

        if( root->val == temp->val )
        {
            temp = temp->next;
            stack_1.push(temp);

            DFS(root->left);
            DFS(root->right);      

            stack_1.pop();

        }else{
            DFS(root->left);
            DFS(root->right);
        }
        return;
    }
};

int main(){



    return 0;
}