#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = 100000;
        int maxprofit = 0;
        int length = prices.size();
        for (int i =0; i < length; i++){
            if(prices[i] < minprice){
                minprice = prices[i];
            }
            if(prices[i] - minprice > maxprofit){
                maxprofit = prices[i] - minprice;
            }
        }
        return maxprofit;
    }
};