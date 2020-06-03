/*有个内含单词的超大文本文件，给定任意两个单词
找出在这个文件中这两个单词的最短距离(相隔单词数)。
如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?


输入：words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
输出：1

自己写的程序 时间耗时有点严重
*/

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        map<string, int> hash_table;
        int length = words.size();
        int i =0; 
        int min_distance = 1000000;
        for(i=0; i<length; i++){
            if(words[i]==word1){
                hash_table[words[i]] = i;
                // word1 : index_i  键值对
            }
            if(words[i] == word2){
                hash_table[words[i]] = i;
                //word2 : index_i 键值对
            }

            if(hash_table[word1] != 0 && hash_table[word2] != 0)
            {
                int distance = abs( hash_table[word2] - hash_table[word1]);
                if(distance < min_distance)
                    min_distance = distance;
            }
            
        }
        return min_distance;
    }
};



//官方的解法
//不用hasp   使用两个int 变量记录一下 index 就好了
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {

        int t1 = -1, t2 = -1, res = words.size();
        for (int i = 0; i < words.size(); i ++) {
            if (words[i] == word1) 
                t1 = i;
            if (words[i] == word2) 
                t2 = i;
            if (t1 != -1 && t2 != -1) 
                res = min(res, abs(t1 - t2));
            if (res == 1) break;
        }
        return res;
    }
};
