class Solution {
public:
int minDifference(vector<int>& nums) {
const int n = nums.size();
if (n < 5)
      return 0;

    int ans = INT_MAX;

    sort(begin(nums), end(nums));

    for (int i = 0; i <= 3; ++i)
      ans = min(ans, nums[n - 4 + i] - nums[i]);

    return ans;
  }
};
