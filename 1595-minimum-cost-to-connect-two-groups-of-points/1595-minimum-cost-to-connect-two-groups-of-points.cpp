class Solution {
    int dp[13][4096] = {};
    int dfs(vector<vector<int>> &cost, vector<int> &mn, int i, int mask) {
        if (dp[i][mask] != -1) return dp[i][mask];
        int ans = i < cost.size() ? INT_MAX : 0;
        if (i < cost.size()) {
            for (int j = 0; j < cost[0].size(); ++j) {
                ans = min(ans, cost[i][j] + dfs(cost, mn, i + 1, mask | (1 << j))); // for nodes in the 1st group, use DP to get the min cost.
            } 
        } else {
            for (int j = 0; j < cost[0].size(); ++j) {
                if ((mask & (1 << j)) == 0) ans += mn[j]; // for those unconnected nodes in the 2nd group, pick the min cost to connect to the 1st group
            }
        }
        return dp[i][mask] = ans;
    }
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        memset(dp, -1, sizeof(dp));
        vector<int> mn(cost[0].size(), INT_MAX); // mn[j] is the minimal cost to connect jth node in the 2nd group to a node in the 1st group
        for (int j = 0; j < mn.size(); ++j) {
            for (int i = 0; i < cost.size(); ++i) mn[j] = min(mn[j], cost[i][j]);
        }
        return dfs(cost, mn, 0, 0);
    }
};