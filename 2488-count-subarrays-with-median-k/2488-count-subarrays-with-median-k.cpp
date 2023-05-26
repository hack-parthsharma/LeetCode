class Solution {
 public:
  int countSubarrays(vector<int>& nums, int k) {
    const int kIndex = find(begin(nums), end(nums), k) - begin(nums);
    int ans = 0;
    unordered_map<int, int> count;

    for (int i = kIndex, balance = 0; i >= 0; --i) {
      if (nums[i] < k)
        --balance;
      else if (nums[i] > k)
        ++balance;
      ++count[balance];
    }

    for (int i = kIndex, balance = 0; i < nums.size(); ++i) {
      if (nums[i] < k)
        --balance;
      else if (nums[i] > k)
        ++balance;
      // The subarray that has balance == 0 or 1 have a median equal to k.
      // So, we should add count[0 - balance] and count[1 - balance] to the ans.
      ans += count[-balance] + count[1 - balance];
    }

    return ans;
  }
};
