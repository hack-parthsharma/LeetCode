class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xs = 0;
        for (int& x : nums) {
            xs ^= x;
        }
        int mask = (1 << maximumBit) - 1;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int x = nums[n - i - 1];
            int k = xs ^ mask;
            ans[i] = k;
            xs ^= x;
        }
        return ans;
    }
};