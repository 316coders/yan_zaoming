/*
在遍历中的每个节点处，我们输出 D 条短划线
（其中 D 是该节点的深度），
然后输出该节点的值。
（如果节点的深度为 D，
则其直接子节点的深度为 D + 1。
根节点的深度为 0）。

如果节点只有一个子节点，
那么保证该子节点为左子节点。

输入："1-2--3--4-5--6--7"
输出：[1,2,5,3,4,6,7]

输入："1-2--3---4-5--6---7"
输出：[1,2,5,3,null,6,null,4,null,7]

输入："1-401--349---90--88"
输出：[1,401,null,349,88,90]

解题思路：
1 设置双指针 来遍历树。
cur 指针总是指向数字，
curD 用于记录每个节点前有几个‘-’
deepth 记录目前的深度，如果curD>deepth 则是子节点
*/

/**
 * Definition for a binary tree node.
 **/

#include<string>
#include<algorithm>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
int cur=0,curD=0;

public:
    TreeNode* recoverFromPreorder(string S) {
        /* 不能这样 char* c, string s='123';c=s.c_str()
         * 这样 c 最后指向的内容是垃圾，因为s对象被析构了
         * 
         * 这样转化维char[] 
         * char c[20]; string s='123'; strcpy(c,s.c_str())
         * 这样不会出错c_str()返回的是一个临时指针。
         */
        int s_length = S.length();
        char* nums = (char *)malloc(s_length*sizeof(char)); 
        strcpy(nums, S.c_str());

    }

    TreeNode dfs(int depth, char[] nodes){
        int val =0;
        for(; cur< size(nodes))
    }


};
