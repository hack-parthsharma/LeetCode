class Solution {
 public:
  int maxIncreasingGroups(vector<int>& usageLimits) {
    int ans = 1; 
    long long availableLimits = 0;
    sort(usageLimits.begin(), usageLimits.end());
    for (const int usageLimit : usageLimits) {
      availableLimits += usageLimit;
      if (availableLimits >= ans * static_cast<long>(ans + 1) / 2)
        ++ans;
    }
    return ans - 1;
  }
};
