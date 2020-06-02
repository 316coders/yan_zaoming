/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
*/
//这个写法存在一个超时的问题，，，最后一个测试点无法通过，，，

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) 
            return 0;
        map<char,int> hash_table;
        int count=0;
        int max_count=-1;
        int i =0;

        for(i=0; i <s.length(); i++){
            if(hash_table[s[i]] == 0){
                hash_table[s[i]]++;
                count++;
                if(count > max_count)
                    max_count = count;
            }else{
                i = i-count+1;
                hash_table.erase(hash_table.begin(),hash_table.end());
                hash_table[s[i]]++;
                count=1;
            }
        }
        return max_count;
    }
};