class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    const int m = obstacleGrid.size();
    const int n = obstacleGrid[0].size();
    vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
    dp[0][1] = 1;  
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (!obstacleGrid[i - 1][j - 1])
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    return dp[m][n];
  }
};
