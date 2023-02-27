class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        
        const int max_value = 1024; //0 <= nums[i] < 2^10
        int n = nums.size();
        
        //freq[i][v] means frequency of the number `v` at `i` position in [0, k-1];
        vector<vector<int>> freq(k, vector<int>(max_value, 0));
        for (int i=0; i<n; i++) {
            freq[i%k][nums[i]]++;
        }
        //dp[i][v] means minimum number of changes in first i elements such that the xor value is `v`
        vector<vector<int>> dp(k, vector<int>(max_value, n+1));
        
        //initailization
        int minChanges = n + 1;
        for (int v = 0; v < max_value; v++) {
            int cntOfPos = n / k + (((n % k) > 0) ? 1 : 0);
            dp[0][v] = cntOfPos - freq[0][v];
            minChanges = min(minChanges, dp[0][v]);
        } 
        
        for (int i=1; i<k; i++) {
            // how many i indices exist in the array
            int cntOfPos = n / k + (((n % k) > i) ? 1 : 0);

            //track minimum changes
            int m = n + 1;
            
            //for all of possible values
            for (int v = 0; v < max_value; v++) {

                for (int j = i; j < n; j += k) {
                    int x = v ^ nums[j];
                    dp[i][v] = min( dp[i][v], dp[i-1][x] + cntOfPos - freq[i][nums[j]]);
                }
                //for all of numbers don't occur at index i
                dp[i][v] = min(dp[i][v], minChanges + cntOfPos);

                m = min(m, dp[i][v]);
            }
            minChanges = m;
        }   
        return dp[k-1][0];
    }
    
};
