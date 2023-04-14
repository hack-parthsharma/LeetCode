class Solution {
public:
    int numberOfSets(int n, int k) {
        long mod = 1e9+7;
        vector<long> presum(k + 1);
        vector<vector<long>> dp(n + 1, vector<long>(k + 1));
        for (int i = 0; i < n; ++i) dp[i + 1][0] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                presum[j - 1] = (presum[j - 1] + dp[i - 1][j - 1]) % mod;
                dp[i][j] = (dp[i - 1][j] + presum[j - 1]) % mod;
            }
        }
        return dp[n][k];
    }
};