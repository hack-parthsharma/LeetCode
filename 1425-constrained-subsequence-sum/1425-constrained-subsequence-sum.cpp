class Solution {
 public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    vector<int> dp(nums.size());
    deque<int> q;
for (int i = 0; i < nums.size(); ++i) {
      if (q.empty())
        dp[i] = nums[i];
      else
        dp[i] = max(q.front(), 0) + nums[i];
      while (!q.empty() && q.back() < dp[i])
        q.pop_back();
      q.push_back(dp[i]);
      if (i >= k && dp[i - k] == q.front())
        q.pop_front();
    }

    return *max_element(begin(dp), end(dp));
  }
};
