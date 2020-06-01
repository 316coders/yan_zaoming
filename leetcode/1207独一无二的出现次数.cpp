/*
输入：arr = [1,2,2,1,1,3]
输出：true
解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。

输入：arr = [1,2]
输出：false
1出现了一次  2也出现了一次
*/
#include<iostream>

#include<unordered_map>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> hash;
        for(int num:arr)
        {
            hash[num]++;
            //比如num=2这是个key 则hash[]对应的值要+1
        }

        set<int> st;
        for(auto it:hash)
        {
            //it.second 表示这个键值对中的值 
            if(st.find(it.second)!=st.end()) 
            //这个表示找到了 ！=st.end()
                return false;

            st.insert(it.second);
            //如果在set集合中没有发现 这个count数字 则把它给插入到set集合中
        }
        return true;
    }
};

int main(){
    Solution s;
    int  a [8]={1,2,3,4,5,4,3,3};
    vector<int> vec(a, a+8);
    bool B = s.uniqueOccurrences(vec);

    cout << (B) << endl;
    return 0;
}

