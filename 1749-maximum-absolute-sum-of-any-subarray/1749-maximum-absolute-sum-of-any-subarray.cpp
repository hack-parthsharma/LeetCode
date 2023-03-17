class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        return maxAbsoluteSum02(nums); //56ms
        return maxAbsoluteSum01(nums); //56ms
    }
    
    
    
    int maxAbsoluteSum01(vector<int>& nums) {
        return std::max(maxSumArray(nums), std::abs(minSumArray(nums)) );
    }
    
    //https://en.wikipedia.org/wiki/Maximum_subarray_problem
    int maxSumArray(vector<int>& nums) {
        int max = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (sum < 0 ) sum = nums[i];
            else sum += nums[i];
            if (max < sum) max = sum;
        }
        return max;
    }
    
    int minSumArray(vector<int>& nums) {
        int min = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (sum > 0 ) sum = nums[i];
            else sum += nums[i];
            if (min > sum) min = sum;
        }
        return min;
    }
    
    // Becasue maxSumArray() & minSumArray() are two similar,
    // we can merge them together to save one loop
    int maxAbsoluteSum02(vector<int>& nums) {
        int max = nums[0];
        int max_sum = nums[0];
        
        int min = nums[0];
        int min_sum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            
            if (max_sum < 0 ) max_sum = nums[i];
            else max_sum += nums[i];
            if (max < max_sum) max = max_sum;
            
            
            if (min_sum > 0 ) min_sum = nums[i];
            else min_sum += nums[i];
            if (min > min_sum) min = min_sum;
            
        }
        
        return std::max(max, abs(min));
    }
    
};
