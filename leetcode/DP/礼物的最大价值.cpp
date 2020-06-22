/*
输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物

使用DP 维护每处走过的价值，记录下来。
动态规划方程
*/
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i =0 ; i < m ; i ++){
            for(int j =0; j < n; j++){
                if(i==0 && j!=0){
                    grid[i][j]=grid[i][j-1] + grid[i][j];
                }
                if(i!=0 && j==0){
                    grid[i][j] = grid[i-1][j] + grid[i][j];
                }
                if(i!=0 && j!=0){
                    int temp = max(grid[i-1][j], grid[i][j-1]);
                    grid[i][j] = temp + grid[i][j];
                }

            }
        }
        int max = grid[m-1][n-1];
        return max;
    }
};