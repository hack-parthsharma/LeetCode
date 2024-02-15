class Solution {
public:
  long long largestPerimeter(vector<int>& nums) {
    long long prefix = accumulate(nums.begin(), nums.end(), 0LL);

    ranges::sort(nums);

    for (int i = nums.size() - 1; i >= 2; --i) {
      prefix -= nums[i];
      if (prefix > nums[i])
        return prefix + nums[i];
    }

    return -1;
  }
};