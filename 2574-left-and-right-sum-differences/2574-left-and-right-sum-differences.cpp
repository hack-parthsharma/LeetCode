class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int ps = 0, ss = 0;
        for(auto &i: nums)ss += i;//get suffix sum
        vector<int> ans;
        for(auto &i: nums){
            ss -= i;//sum of i+1 to n
            ans.push_back(abs(ss-ps));
            ps += i;//sum of 0 to i
        }
        return ans;
    }
};