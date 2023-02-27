class Solution {
public:
    long sum(vector<int>& nums) {
        long s = 0;
        for (auto n : nums) {
            s += n;
        }
        return s;
    }
    int minElements(vector<int>& nums, int limit, int goal) {
        long s = sum(nums);
        return (abs(goal - s) + limit -1) / limit;
    }
};
