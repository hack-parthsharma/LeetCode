class Solution {
 public:
  int numberOfWays(int n, int x) {
    constexpr int kMod = 1'000'000'007;
    vector<int> dp(n + 1);
    int ax; 
    dp[0] = 1;
    for (int a = 1; (ax = pow(a, x)) <= n; ++a)
      for (int i = n; i >= ax; --i) {
        dp[i] += dp[i - ax];
        dp[i] %= kMod;
      }

    return dp[n];
  }
};
