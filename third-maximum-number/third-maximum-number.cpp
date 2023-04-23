class Solution {
public:
    int nMax(vector<int>& nums, int n) {
        set<int> topN;
        for(auto num : nums) {
            topN.insert(num);
            if (topN.size() > n) topN.erase(topN.begin());
        }
        return (topN.size() >= n) ? *(topN.begin()) : *(topN.rbegin());
    }
    int thirdMax(vector<int>& nums) {
        return nMax(nums, 3);
    }
};