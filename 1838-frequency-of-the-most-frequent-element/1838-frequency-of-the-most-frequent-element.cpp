class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int m = 1;
        int start = 0;
        int i = 1;
        for(; i<nums.size(); i++){
            long delta = nums[i] - nums[i-1];
            k -= delta * (i - start);;
            if (k < 0 )  {
                // remove the first one
                k += (nums[i] - nums[start]) ;
                start++;
            }
            m = max(m, i - start +1);
            
        }
        return m;
    }
};