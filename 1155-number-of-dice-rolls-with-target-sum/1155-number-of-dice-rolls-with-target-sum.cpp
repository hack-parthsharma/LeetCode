class Solution {
 public:
  int numRollsToTarget(int n, int k, int target) {
    constexpr int kMod = 1'000'000'007;
    vector<int> dp(target + 1);
    dp[0] = 1;
    while (n--) {  
      vector<int> newDp(target + 1);
      for (int i = 1; i <= k; ++i)           
        for (int t = i; t <= target; ++t) {  
          newDp[t] += dp[t - i];
          newDp[t] %= kMod;
        }
      dp = move(newDp);
    }
    return dp[target];
  }
};
