class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = maxSum;
        for(int i=1; i<nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                sum += nums[i];
            }else{
                maxSum = maxSum < sum ? sum : maxSum;
                sum = nums[i];
            }
        }
        maxSum = maxSum < sum ? sum : maxSum;
        return maxSum;
    }
};