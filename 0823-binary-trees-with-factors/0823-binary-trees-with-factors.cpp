class Solution {
 public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    constexpr int kMod = 1'000'000'007;
    const int n = arr.size();
    vector<long> dp(n, 1);
    unordered_map<int, int> numToIndex;

    sort(begin(arr), end(arr));
    for (int i = 0; i < n; ++i)
      numToIndex[arr[i]] = i;
    for (int i = 0; i < n; ++i)  
      for (int j = 0; j < i; ++j)
        if (arr[i] % arr[j] == 0) { 
          const int right = arr[i] / arr[j];
          if (const auto it = numToIndex.find(right); it != cend(numToIndex)) {
            dp[i] += dp[j] * dp[it->second];
            dp[i] %= kMod;
          }
        }
    return accumulate(begin(dp), end(dp), 0L) % kMod;
  }
};
