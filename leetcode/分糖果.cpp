#include<vector>
#include<algorithm>

using namespace std;

/*
排序需要 O(nlog n)的时间
c++中使用标注库 算法模板
*/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        int count=1;
        int length_candies = candies.size();
        for(int i =1; i < length_candies&& count< length_candies/2; i++){
            if(candies[i] > candies[i-1])
                count++;
        }
        return count;
    }
};

/*
    我们使用集合的唯一性来统计 糖果的种类
    
    set是一种包含已排序对象的关联容器。set会根据待定的排序准则，
　　自动将元素排序。set不允许元素重复。
1) 不能直接改变元素值，因为那样会打乱原本正确的顺序，
    要改变元素值必须先删除旧元素，则插入新元素.
2)不提供直接存取元素的任何操作函数，只能通过迭代器进行间接存取，
    而且从迭代器角度来看，元素值是常数.
3)元素比较动作只能用于型别相同的容器(即元素和排序准则必须相同)

      set<int> s;  
      s.insert(5); //第一次插入5，可以插入  
      s.insert(1);  
      s.insert(6);  
      s.insert(3);  
      s.insert(5); //第二次插入5，重复元素，不会插入  
      set<int>::iterator it; //定义前向迭代器  
      //中序遍历集合中的所有元素  
      for(it = s.begin(); it != s.end(); it++)  
      {  
         cout << *it << " ";  
      }  

使用反向迭代器reverse_iterator可以反向遍历集合，输出的结果正好是集合元素的反向排序结果。
    set<int>::reverse_iterator rit; //定义反向迭代器  
    //反向遍历集合中的所有元素  
    for(rit = s.rbegin(); rit != s.rend(); rit++)  
    {  
        cout << *rit << " ";  
    }  


元素的删除
       集合具有高效的删除处理功能，并自动重新调整内部的红黑树的平衡。
　删除可以某个迭代器位置上的元素、等于某键值的元素、一个区间上的元素、清空集合。
set<int>::iterator it; 声明迭代器的方式
it = s.begin();  
for(int i = 0; i < 2; i++)  
    it = s.erase(it);  

5.元素的检索
    使用find()方法对集合进行检索，如果找到查找的的键值，则返回该键值的迭代器位置；
　　否则，返回集合最后一个元素后面的一个位置，即end()
it = s.find(6); //查找键值为6的元素  
if(it != s.end())  
    cout << *it << endl;  
else  
    cout << "not find it" << endl; 

第二种方式 使用count()这个函数来统计
if(!s.count(a)) //不存在  
    printf("does not exist\n");  

*/
#include<set>
#include<unordered_set>
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> set;
        set.reserve(candies.size()*4);

        for(int i=0; i < candies.size(); i++){
            set.insert(candies.at(i));
        }
        //比较一半的糖果数 与 种类总数 选更小的
        return min(candies.size() / 2, set.size());
    }
};
