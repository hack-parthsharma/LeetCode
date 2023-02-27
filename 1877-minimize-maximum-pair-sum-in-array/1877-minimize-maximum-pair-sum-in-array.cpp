class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int m = 0;
        for(int i = 0, j = nums.size() - 1; i < j; i++,j--) {
            m = max(m, nums[i] + nums[j]);
        }
        return m;
    }
};
