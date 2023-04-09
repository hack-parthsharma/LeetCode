class Solution {
public:
    int minStartValue(vector<int>& nums) {
        partial_sum(begin(nums), end(nums), begin(nums));
        int m = *min_element(begin(nums), end(nums));
        return 1 - min(0, m);
    }
};
