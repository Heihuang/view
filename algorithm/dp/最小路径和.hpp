/*
题目：给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步
解法：
状态定义：
设dp为大小m*n矩阵，其中dp[i][j]的值代表直到走到(i,j)的最小路径和。
转移方程：
当i > 0且j=0时，dp[i][0] = dp[i-1][0] + grid[i][0];
当i=0且j>0时，dp[0][j] = dp[0][j-1] + grid[0][j];
当i>0且j>0时，dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
最后得到dp[m-1][n-1]的值即为从网格左上角到网格右下角的最小路径和。
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int rows = grid.size(), columns = grid[0].size();
        auto dp = vector < vector <int> > (rows, vector <int> (columns));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < columns; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[rows - 1][columns - 1];
    }
};
