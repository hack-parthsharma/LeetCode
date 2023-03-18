class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            return minCostClimbingStairs02(cost); 
            return minCostClimbingStairs01(cost); 
        }
        int minCostClimbingStairs01(vector<int>& cost) {
            vector<int> dp(cost.size() , 0);
            dp[0] = cost[0];
            dp[1] = cost[1];
            for (int i=2; i<cost.size(); i++) {
                dp[i] = min( dp[i-1], dp[i-2] ) + cost[i];
            }
            return min(dp[dp.size()-1], dp[dp.size()-2]);
        }

        int minCostClimbingStairs02(vector<int>& cost) {
            int dp1 = cost[0], dp2 = cost[1];
            for (int i=2; i<cost.size(); i++) {
                int dp = min( dp1, dp2 ) + cost[i];
                dp1 = dp2;
                dp2 = dp;
            }
            return min (dp1, dp2);
        }
};