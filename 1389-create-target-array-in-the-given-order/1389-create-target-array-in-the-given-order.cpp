class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans;
        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            ans.insert(ans.begin() + index[i], nums[i]);
        }
        return ans;
    }
};