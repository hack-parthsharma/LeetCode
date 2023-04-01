class Solution {
 public:
  int smallestRangeII(vector<int>& nums, int k) {
    sort(begin(nums), end(nums));

    int ans = nums.back() - nums.front();
    const int left = nums.front() + k;
    const int right = nums.back() - k;

    for (int i = 0; i + 1 < nums.size(); ++i) {
      const int mini = min(left, nums[i + 1] - k);
      const int maxi = max(right, nums[i] + k);
      ans = min(ans, maxi - mini);
    }

    return ans;
  }
};
