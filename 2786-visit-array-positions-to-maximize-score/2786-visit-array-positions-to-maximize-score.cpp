class Solution {
 public:
  long long maxScore(vector<int>& nums, int x) {
    long long dp0 = nums[0] - (nums[0] % 2 == 1 ? x : 0);
    long long dp1 = nums[0] - (nums[0] % 2 == 0 ? x : 0);

    for (int i = 1; i < nums.size(); ++i)
      if (nums[i] % 2 == 0)
        dp0 = nums[i] + max(dp0, dp1 - x);
      else
        dp1 = nums[i] + max(dp1, dp0 - x);

    return max(dp0, dp1);
  }
};
