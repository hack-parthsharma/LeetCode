class Solution {
 public:
  int minPatches(vector<int>& nums, int n) {
    int ans = 0;
    int i = 0;      
    long miss = 1;  

    while (miss <= n)
      if (i < nums.size() && nums[i] <= miss) {
        miss += nums[i++];
      } else {
        // Greedily add miss itself to increase the range
        // From [1, miss) to [1, 2 * miss)
        miss += miss;
        ++ans;
      }

    return ans;
  }
};
