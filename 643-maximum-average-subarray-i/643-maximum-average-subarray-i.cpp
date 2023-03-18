class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0; i<k; i++ ) {
            sum += nums[i];
        }
        
        int s = sum;
        for (int i=k; i< nums.size(); i++) {
            s += nums[i];
            s -= nums[i-k];
            
            if (s > sum) {
                sum = s;
            }
        }
        return (double)sum/k;
    }
};