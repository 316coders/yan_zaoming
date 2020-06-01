#include<vector>
#include<map>
#include<iostream>
using namespace std;

int repeatedNTimes(vector<int>& A) {
        int length  = A.size();
        int N = (length+1)/2;
        int res;

        map<int,int> hash;
        for(int i =0; i < length; i++){
            hash[A[i]]++;
        }
        for(auto it:hash){
            if(it.second==N)
            {
                res = it.first;
            }
        }
        return res;
    }

int main(){
    int a[5] = {1,2,3,3};
    vector<int> A(a,a+4);
    int aa = repeatedNTimes(A);
    
    return 0;
}