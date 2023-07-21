class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    int maxLength = 0;
    vector<int> length(n, 1);  
    vector<int> count(n, 1);   

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[j] < nums[i])
          if (length[i] < length[j] + 1) {
            length[i] = length[j] + 1;
            count[i] = count[j];
          } else if (length[i] == length[j] + 1) {
            count[i] += count[j];
          }
    for (int i = 0; i < n; ++i)
      if (length[i] > maxLength) {
        maxLength = length[i];
        ans = count[i];
      } else if (length[i] == maxLength) {
        ans += count[i];
      }
    return ans;
  }
};
