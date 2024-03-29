class Solution {
 public:
  int alternatingSubarray(vector<int>& nums) {
    int ans = 1;
    int dp = 1;

    for (int i = 1; i < nums.size(); ++i) {
      const int targetDiff = dp % 2 == 0 ? -1 : 1;
      if (nums[i] - nums[i - 1] == targetDiff)
        ++dp;
      else if (nums[i] - nums[i - 1] == 1)
        dp = 2;
      else
        dp = 1;
      ans = max(ans, dp);
    }
    return ans == 1 ? -1 : ans;
  }
};
