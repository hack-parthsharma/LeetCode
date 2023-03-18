class Solution {
private:
    int min(int x, int y){
        return x < y ? x : y;
    }
    int min(int x, int y, int z) {
        return min(min(x, y), z);
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        // Dynamic Programming
        vector<int> dp(days.size()+1, INT_MAX);

        // dp[i] is the minimal cost from Days[0] to Days[i]
        dp[0] = 0;
        dp[1] = min(costs[0], costs[1], costs[2]);

        for (int i = 2; i<= days.size(); i ++) {

            // the currnet day need at least min(1-day, 7days, 30days) from previous.
            int m = dp[i-1] + min(costs[0], costs[1], costs[2]);

            // Seprating the array to two parts.
            //     days[0] -> days[j] -> day[i]
            //
            // calculate the day[i] - day[j] whether can use 7-day pass or 30-day pass
            //
            // Traking the minimal costs, then can have dp[i] minimal cost

            int SevenDays = INT_MAX, ThrityDays = INT_MAX;
            for (int j=i-1; j>0; j--){
                int gaps = days[i-1] - days[j-1];
                if ( gaps < 7 )  {
                    // can use 7-days or 30-days ticket
                    SevenDays  = dp[j-1] + min(costs[1], costs[2]);
                } else if (gaps < 30 ) {
                    //can use 30-days tickets
                    ThrityDays = dp[j-1] + costs[2];
                } else {
                    break;
                }
                m = min(m, SevenDays, ThrityDays);
            }
            if ( dp[i] > m )  dp[i] = m;
        }
        
        return dp[dp.size()-1];    
    }
};